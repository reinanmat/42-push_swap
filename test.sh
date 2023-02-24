#!/usr/bin/bash

i=0
while [[ i -lt 120 ]]; do
    ARG=$(shuf -i 0-5 -n 5)
    val=$(./push_swap $ARG | wc -l)
    if [[ val -gt 12 ]]; then
        echo "DANGER"
        printf "program failed with params\n${ARG}\n" > failed.txt
        exit 1
    fi
    printf "With params \n${ARG}\n used ${val} operations, great job\n"
    let i=i+1
done
