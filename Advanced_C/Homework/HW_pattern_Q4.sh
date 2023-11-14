#! /bin/bash

read -p "Enter the number of rows: " n

alphabets=({A..Z})

for row in `seq $n`
do
    for space in `seq $row $(($n-1))`
    do
	echo -n " "
    done


    for alphabet in `seq 0  $(($row - 1))`
    do
	echo -n "${alphabets[$alphabet]}"
    done


    for alphabet in `seq $(($row - 2)) -1 0`
    do
	echo -n "${alphabets[$alphabet]}"
    done

    echo "" 
done

