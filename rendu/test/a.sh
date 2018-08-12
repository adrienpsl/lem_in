#!/usr/bin/env bash

for file in `cd fourmis ; ls`
    do
        if [[ "$file" != "lem" && "$file" != "a.sh" ]]
        then
                echo "$file"
                ./lem < "fourmis/$file"
        fi
done
