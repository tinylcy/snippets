#!/bin/bash
echo -n "" > data

for k in $( seq 1 10)
do
    go test
done

python average.py
