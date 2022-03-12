#!/bin/python3
from sys import argv


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
THINKING = 0
EATING = 1
SLEEPING = 2

MSG_GRABBED_EATING = " grabbed a fork while eating!"
MSG_GRABBED_MANY = " has {0} forks!"
MSG_GRABBED_SLEEPING = " grabbed a fork while sleeping!"
MSG_LATE_MEAL = "'s meal is too late! It should be dead."
MSG_TIME_TRAVELLER = " is a time traveller! Its current event has a lower timestamp than its previous event."


# tester_fail: tester compatibility issues with weirdly formatted philosophers lines
# errors and warnings: philosopher errors and weird behaviors
results = {
    "tester_fail": 0,
    "philo_error": 0,
    "philo_warn": 0,
}


class PhiloEval:
    all_meals_eaten = 0
    check_meal_count = True if N_MUST_EAT >= 0 else False
    all_forks_grabbed = 0


    def __init__(self, id: int) -> None:
        self.id = id
        self.status = 0
        self.time_of_last_event = 0

        self.forks_grabbed = 0
        self.time_of_last_meal = 0

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


    def check_for_time_traveller(self, line, time_now):
        if self.time_of_last_event > time_now:
            self.log_fail(line, MSG_TIME_TRAVELLER, "philo_error")


    def check_if_neighbors_also_have_two_forks(self):
        pass


    def check_if_really_alive(self, line, time_now):
        if time_now >= self.time_of_last_meal + TIME_TO_DIE + 10:
            self.should_be_dead = True
            self.log_fail(line, MSG_LATE_MEAL, "philo_error")


    def check_grabbed_fork(self, line, time_now):
        if self.status == SLEEPING:
            self.log_fail(line, MSG_GRABBED_SLEEPING, "philo_error")

        if self.status == EATING:
            self.log_fail(line, MSG_GRABBED_EATING, "philo_error")

        self.forks_grabbed += 1
        if self.forks_grabbed > 2:
            self.log_fail(line, MSG_GRABBED_MANY.format(self.forks_grabbed), "philo_error")


    def check_eating(self, line, time_now):
        if self.forks_grabbed < 2:
            self.log_fail(line, " is eating without two forks!", "philo_error")
        self.time_of_last_meal = time_now


    def check_sleeping(self, line, time_now):
        self.forks_grabbed -= 2
        self.all_forks_grabbed -= 2


    def check_thinking(self, line, time_now):
        pass


    def check_death(line, time_now):
        pass


    def check_event(self, line, time_now, description: str):
        self.check_for_time_traveller(line, time_now)
        if (self.is_dead is False):
            self.check_if_really_alive(line, time_now)

        if "fork" in description:
            self.check_grabbed_fork(line, time_now)
        elif "eating" in description:
            self.check_eating(line, time_now)
        elif "sleeping" in description:
            self.check_sleeping(line, time_now)
        elif "thinking" in description:
            self.check_thinking(line, time_now)
        elif "died" in description:
            self.check_death(line, time_now)
        else:
            self.log_fail(line, f": unknown event '{description}'!", "philo_error")

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
        results["tester_fail"] += 1
        print(f"Line {line}: philosopher has invalid id '{split_str[1]}'")
        continue

    if id not in range(1, N_PHILOS + 1):
        print(f"Line {line}: philosopher has invalid id '{split_str[1]}'")
        continue

    philos[id].check_event(line, split_str[0], split_str[2:])


exit(1 if results["philo_error"] else 2 if results["philo_warn"] else 0)
