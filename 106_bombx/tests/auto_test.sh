#!/usr/bin/env bash
##
## EPITECH PROJECT, 2021
## auto test
## File description:
## bash test
##

YELLOW='\e[1;33m'
GREEN='\e[1;32m'
RED='\e[1;91m'
WHITE='\e[1;39m'
neutre='\e[0;39m'
cyanclair='\e[1;36m'
MAGENTA='\e[1;35m'
BLUE='\e[0;34m'

nbr_tests=0
nbr_tests_passed=0
nbr_tests_fail=0

strstr() {
  [ "${1#*$2*}" = "$1" ] && return 1
  return 0
}

tests_file()
{
    ./106bombyx $1 > my_out
    diff <(cat my_out) <(cat $2)
    if [ "$?" -eq 0 ]
    then
        printf "${cyanclair}Test %-2d : ${WHITE}%-60s${GREEN}PASSED${neutre}\n" $(($nbr_tests + 1)) $line
        nbr_tests_passed=$(($nbr_tests_passed + 1))
    else
        printf "${cyanclair}Test %-2d : ${WHITE}%-60s${RED}FAIL${neutre}\n" $(($nbr_tests + 1)) $line
        nbr_tests_fail=$(($nbr_tests_fail + 1))
    fi
    nbr_tests=$(($nbr_tests + 1))
}

printf "${WHITE}<${GREEN}===== ${MAGENTA}TESTS FILES ${GREEN}=====${WHITE}>\n${neutre}"
tests_file "10 3.3" "file_test/data"
tests_file " 10 10000 10010" "file_test/data1"
tests_file "100 2" "file_test/data2"
tests_file "100 2 10" "file_test/data3"


printf "\n[${BLUE}====${neutre}] ${WHITE} Synthesis: Tested: ${BLUE}$nbr_tests${WHITE} | Passing: ${GREEN}$nbr_tests_passed${WHITE} | Failing: ${neutre}"

if [ $nbr_tests_fail -eq 0 ]
then
    printf "$nbr_tests_fail \n"
else
    printf "${RED}$nbr_tests_fail${neutre}\n"
fi

rm -f my_out
rm -f shell_out
