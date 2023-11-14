#! /bin/bash

read -p "Enter how many rows: " n

for row in `seq $n`
do
    for num1 in `seq $(($n - $row + 1))`
    do
	echo -n "$num1"
    done


    for space in `seq $(($row - 1))`
    do
	echo -n "__"
    done


    for num2 in `seq $(($n - $row + 1)) -1 1`
    do
	echo -n "$num2"
    done

    echo ""
done

