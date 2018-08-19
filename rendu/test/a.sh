#!/usr/bin/env bash

function set_sep()
{
    echo "/*------------------------------------*\ "
    echo "     -- $1 --"
    echo "\*------------------------------------*/ "
}

function run_test()
{
    name_test="$1"
    set_sep "test $name_test"

    for file in `cd "$name_test" ; ls`
        do
            if [[ "$file" != "lem-in" && "$file" != "a.sh" ]]
            then
                    echo "\033[1;31m----> $file \033[0m"
                    ./lem-in < "$name_test/$file" | head -n 1
            fi
    done
    echo
}


run_test "1__bad_ants"
run_test "2__err_room"
run_test "3__link_no_work"
run_test "4__link_work"
run_test "5__comment"
run_test "other_test"
run_test "other_good"
run_test "test_violent"
