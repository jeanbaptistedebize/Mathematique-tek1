
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

test_check_diff()
{
    diff $1 $2
    if [ "$?" -eq 0 ]
        then
            printf "${cyanclair}Test %-2d : ${WHITE}%-60s${GREEN}PASSED${neutre}\n" $(($nbr_tests + 1)) $2
            nbr_tests_passed=$(($nbr_tests_passed + 1))
        else
            printf "${cyanclair}Test %-2d : ${WHITE}%-60s${RED}FAIL${neutre}\n" $(($nbr_tests + 1)) $2
            nbr_tests_fail=$(($nbr_tests_fail + 1))
    fi
}

test_fonc()
{
    ./110borwein $1 > out
    test_check_diff "out" $2
    nbr_tests=$(($nbr_tests + 1))
}

printf "${WHITE}<${GREEN}===== ${MAGENTA}TESTS FILES ${GREEN}=====${WHITE}>\n${neutre}"
test_fonc 0 tests/test_outout/test_0
test_fonc 10 tests/test_outout/test_10
test_fonc 42 tests/test_outout/test_42
test_fonc -h tests/test_outout/test_usage

printf "\n[${BLUE}====${neutre}] ${WHITE} Synthesis: Tested: ${BLUE}$nbr_tests${WHITE} | Passing: ${GREEN}$nbr_tests_passed${WHITE} | Failing: ${neutre}"

if [ $nbr_tests_fail -eq 0 ]
then
    printf "$nbr_tests_fail \n"
else
    printf "${RED}$nbr_tests_fail${neutre}\n"
fi

rm -f file*.test
rm -f out