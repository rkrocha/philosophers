#!/usr/bin/python3
import argparse  # TODO: check it out
from sys import argv


# Adjust these strings in case your philosophers output uses different phrases.
# Replace each string with one that represents that event.
EVENT_FORK = "fork"
EVENT_EATING = "eating"
EVENT_SLEEPING = "sleeping"
EVENT_THINKING = "thinking"
EVENT_DEAD = "died"

MAX_DELAY = 10


# get args from terminal
N_PHILOS = int(argv[2])
TIME_TO_DIE = int(argv[3])
TIME_TO_EAT = int(argv[4])
TIME_TO_SLEEP = int(argv[5])
try:
    N_MUST_EAT = int(argv[6])
except IndexError:
    N_MUST_EAT = -1

# open and read philo output file
try:
    with open(argv[1], "r") as file:
        philo_output = file.read().splitlines()
except FileNotFoundError:
    exit(f"File '{argv[1]}' not found!")


# definitions of philosophers status and error msgs
UNDEFINED = -1
THINKING = 0
EATING = 1
SLEEPING = 2

MSG_FORK_UNAVAILABLE = " grabbed a fork, but its neighbors were already holding two forks each!"
MSG_GRABBED_MANY = " is holding more than two forks!"
MSG_GRABBED_EATING = " grabbed a fork while eating!"
MSG_GRABBED_SLEEPING = " grabbed a fork while sleeping!"
MSG_INVALID_EATING = " did not think before eating!"
MSG_INVALID_SLEEP = " did not eat before sleeping!"
MSG_INVALID_THINK = " did not sleep before thinking!"
MSG_LATE_DEATH = "'s death took more than 10 ms to log! It should be dead already!"
MSG_EARLY_EVENT = " spent too little time in its previous event!"
MSG_LATE_EVENT = " spent too much time in its previous event!"
MSG_MANY_FORKS = " grabbed a fork that does not exist! The number of forks in use is larger than the number of philosophers."
MSG_SINGLE_FORK = " is eating without two forks!"
MSG_TIME_TRAVELLER = " is a time traveller! Its current event has a lower timestamp than its previous event."
MSG_ZOMBIE = " is dead but is still moving! Zombie!"


# tester_error: tester compatibility issues with weirdly formatted philosophers lines
# errors and warnings: philosopher errors and weird behaviors
results = {
    "tester_error": 0,
    "philo_error": 0,
    "philo_warn": 0,
}


class PhiloEval:
    all_meals_eaten = 0  # TODO REMOVE?
    check_meal_count = True if N_MUST_EAT >= 0 else False  # TODO REMOVE?
    all_forks_in_use = 0


    def __init__(self, id: int) -> None:
        self.id = id
        self.status = UNDEFINED
        self.time_of_last_event = 0

        self.forks_grabbed = 0
        self.time_of_last_meal = 0
        self.meals_eaten = 0

        self.is_dead = False
        self.should_be_dead = False
        self.actual_time_of_death = 0
        self.expected_time_of_death = 0


    def log_fail(self, line: int, msg: str, type: str):
        global results
        try:
            results[type] += 1
        except KeyError:
            print(f"Line {line}: {msg}")
        else:
            print(f"Line {line}: philosopher {self.id}{msg}")


    def check_if_time_traveller(self, line, time_now):
        if self.time_of_last_event > time_now:
            self.log_fail(line, MSG_TIME_TRAVELLER, "philo_error")


    def check_time_spent_in_prev_event(self, line, event_duration, time_now):
        if self.status == UNDEFINED:
            return
        time_spent = time_now - self.time_of_last_event
        if time_spent >= event_duration + MAX_DELAY:
            self.log_fail(line, MSG_LATE_EVENT, "philo_error")
        if time_spent < event_duration:
            self.log_fail(line, MSG_EARLY_EVENT, "philo_error")


    def check_if_neighbors_also_have_two_forks_each(self, line):
        if N_PHILOS == 1:
            return

        neighbors = []
        neighbors.append(self.id - 1 if self.id != 1 else N_PHILOS)
        if len(philos) > 3:
            neighbors.append(self.id + 1 if self.id != N_PHILOS else 1)

        forks_used_by_neighbors = 0
        for neighbor in neighbors:
            forks_used_by_neighbors += philos[neighbor].forks_grabbed

        if forks_used_by_neighbors >= len(neighbors) * 2:
            self.log_fail(line, MSG_FORK_UNAVAILABLE, "philo_error")


    def check_if_really_alive(self, line, time_now):
        if time_now >= self.time_of_last_meal + TIME_TO_DIE:
            self.should_be_dead = True
            self.expected_time_of_death = self.time_of_last_meal + TIME_TO_DIE


    def check_grabbed_fork(self, line, time_now):
        if self.status == SLEEPING:
            self.log_fail(line, MSG_GRABBED_SLEEPING, "philo_error")

        if self.status == EATING:
            self.log_fail(line, MSG_GRABBED_EATING, "philo_error")

        self.forks_grabbed += 1
        self.all_forks_in_use += 1
        self.check_if_neighbors_also_have_two_forks_each(line)

        if self.all_forks_in_use > N_PHILOS:
            self.log_fail(line, MSG_MANY_FORKS, "philo_error")

        if self.forks_grabbed > 2:
            self.log_fail(line, MSG_GRABBED_MANY, "philo_error")


    def check_eating(self, line, time_now):
        if self.status not in [THINKING, UNDEFINED]:
            self.log_fail(line, MSG_INVALID_EATING, "philo_error")
        if self.forks_grabbed < 2:
            self.log_fail(line, MSG_SINGLE_FORK, "philo_error")
        self.time_of_last_meal = time_now
        self.status = EATING


    def check_sleeping(self, line, time_now):
        if self.status not in [EATING, UNDEFINED]:
            self.log_fail(line, MSG_INVALID_SLEEP, "philo_error")
        self.check_time_spent_in_prev_event(line, TIME_TO_EAT, time_now)
        self.meals_eaten += 1
        self.all_forks_in_use -= self.forks_grabbed
        self.forks_grabbed = 0
        self.status = SLEEPING


    def check_thinking(self, line, time_now):
        if self.status not in [SLEEPING, UNDEFINED]:
            self.log_fail(line, MSG_INVALID_THINK, "philo_error")
        self.check_time_spent_in_prev_event(line, TIME_TO_SLEEP, time_now)
        self.status = THINKING


    def check_death(self, line, time_now):
        self.is_dead = True
        self.actual_time_of_death = time_now


    def check_event(self, line: int, time_now: int, description: str):
        if self.is_dead:
            self.log_fail(line, MSG_ZOMBIE, "philo_error")
            return

        if self.should_be_dead is False:
            self.check_if_really_alive(line, time_now)

        if self.should_be_dead and time_now > self.expected_time_of_death + MAX_DELAY:
            self.log_fail(line, MSG_LATE_DEATH, "philo_error")

        self.check_if_time_traveller(line, time_now)

        if EVENT_FORK in description:
            self.check_grabbed_fork(line, time_now)
        elif EVENT_EATING in description:
            self.check_eating(line, time_now)
        elif EVENT_SLEEPING in description:
            self.check_sleeping(line, time_now)
        elif EVENT_THINKING in description:
            self.check_thinking(line, time_now)
        elif EVENT_DEAD in description:
            self.check_death(line, time_now)
        else:
            self.log_fail(line, f": unknown event '{description}'!", "philo_warn")

        self.time_of_last_event = time_now


# Populate a list with an N_PHILOS amount of philosophers.
# Since philosopher id ranges from 1 to N_PHILOS (including),
# 'None' is attributed to index 0 for index alignment reasons.
# This way the PhiloEval instance with id 1 is kept on index 1 of this list
philos = [None]
for id in range(1, N_PHILOS + 1):
    philos.append(PhiloEval(id))


# Iterate through each line, formatting, verifying and finally
# sending it to its corresponding PhiloEval by id
for line, str in enumerate(philo_output, 1):
    split_str = str.lower().split()

    try:
        id = int(split_str[1])
    except ValueError:
        results["tester_error"] += 1
        print(f"Line {line}: philosopher has invalid id '{split_str[1]}'")
        continue

    if id not in range(1, N_PHILOS + 1):
        print(f"Line {line}: philosopher has invalid id '{split_str[1]}'")
        continue

    philos[id].check_event(line, int(split_str[0]), ' '.join(split_str[2:]))


exit(1 if results["philo_error"] else 2 if results["philo_warn"] else 0)
