#!/bin/bash


PHILO_PATH=../philo
PHILO_RUN=$PHILO_PATH/philo
TEST_RUN=./philo_tester.py


make -s $PHILO_PATH || exit 1

if command -v tput &>/dev/null && tty -s; then
	RED=$(tput setaf 1)
	GREEN=$(tput setaf 2)
	YELLOW=$(tput setaf 3)
	MAGENTA=$(tput setaf 5)
	NORMAL=$(tput sgr0)
	BOLD=$(tput bold)
else
	RED=$(echo -en "\e[31m")
	GREEN=$(echo -en "\e[32m")
	YELLOW=$(echo -en "\e[33m")
	MAGENTA=$(echo -en "\e[35m")
	NORMAL=$(echo -en "\e[00m")
	BOLD=$(echo -en "\e[01m")
fi

fail=0
optm=0
pass=0

test()
{
	$PHILO_RUN $@ > philo.output
	$TEST_RUN philo.output $@ && ((++pass)) && return
	((++fail))
}

test 3 250 100 100





norminette $PHILO_PATH &>/dev/null && echo -e '\n'${GREEN}Norme: pass'\n' || echo -e '\n'${RED}Norme: fail'\n'

echo ${RED}KO: $fail
echo ${YELLOW}OP: $optm
echo ${GREEN}OK: $pass
