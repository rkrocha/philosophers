#!/bin/python3
from sys import argv


# get args from terminal
N_PHILOS = int(argv[1])
TIME_TO_DIE = int(argv[2])
TIME_TO_EAT = int(argv[3])
TIME_TO_SLEEP = int(argv[4])
try:
    N_MUST_EAT = int(argv[5])
except IndexError:
    N_MUST_EAT = -1

# open and read "test.output" file
try:
    with open("test.output", "r") as file:
        result = file.read().splitlines()
except FileNotFoundError:
    exit("File 'test.output' not found!")


# definitions of philosophers status
THINKING = 0
EATING = 1
SLEEPING = 2

# number of tester compatibility issues with weirdly formatted philosophers lines
tester_failure = 0

# philosopher errors and weird behaviors
philo_errors = 0
philo_warnings = 0


class PhiloEval:
    all_meals_eaten = 0
    check_meal_count = True if N_MUST_EAT >= 0 else False

    def __init__(self, id: int) -> None:
        self.id = id
        self.status = 0
        self.forks = 0
        self.time_of_last_event = 0
        self.time_of_last_meal = 0
        self.is_dead = False
        self.should_be_dead = False

    def log_error(line: int, msg: str):
        pass

    def check_for_time_traveller(time_now: int, line: int):
        pass

    def check_grabbed_fork(self, time_now: int, line: int):
        if time_now > self.time_of_last_meal + TIME_TO_DIE:
            self.should_be_dead = True
            print(f"Line {line}: philosopher {self.id}'s meal is too late! It should be dead.")
        if self.status == SLEEPING:
            print(f"Line {line}: philosopher {self.id} grabbed a fork while sleeping!")
        if self.status == EATING:
            print(f"Line {line}: philosopher {self.id} grabbed a fork while eating!")
        self.forks += 1
        if self.forks > 2:
            print(f"Line {line}: philosopher {self.id} has {self.forks} forks!")

    def check_eating(self, time_now: int, line: int):
        if self.forks < 2:
            print(f"Line {line}: philosopher {self.id} is eating without two forks!")
        if time_now > self.time_of_last_meal + TIME_TO_DIE:
            self.should_be_dead = True
            print(f"Line {line}: philosopher {self.id}'s meal is too late! It should be dead.")
            self.forks -= 2
        print(f"Philo {self.id} is eating")

    def check_sleeping(self, time_now: int, line: int):
        print(f"Philo {self.id} is sleeping")

    def check_thinking(self, time_now: int, line: int):
        pass

    def check_event(self, time_now: int, line: int, description: str):
        pass


# Populate a list with an N_PHILOS amount of philosophers.
# Since philosopher id ranges from 1 to N_PHILOS (including),
# 'None' is attributed to index 0 for index alignment reasons.
# This way the PhiloEval instance with id 1 is kept on index 1 of this list
philos = [None]
for id in range(1, N_PHILOS + 1):
    philos.append(PhiloEval(id))


# Iterate through each line, formatting, verifying and finally
# sending it to its corresponding PhiloEval by id
for str, line in result:
    str = str.lower().split()

    try:
        id = int(str[1])
    except ValueError:
        tester_failure += 1
        print(f"Line {line}: philosopher has invalid id {str[1]}")
        continue

    if id not in range(1, N_PHILOS + 1):
        print(f"Line {line}: philosopher has invalid id {str[1]}")
        continue

    philos[id].check_event(str[0], line, str[2:])


exit(1 if philo_errors else 2 if philo_warnings else 0)
