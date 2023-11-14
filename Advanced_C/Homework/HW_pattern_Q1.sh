#! /bin/bash

read -p "Enter the number of rows: " n

for row in `seq $n`
do
    value=$row
    for col in `seq $row`
    do
	echo -n "$value "
	value=$(($value + $n - $col))
    done
    echo ""
done
