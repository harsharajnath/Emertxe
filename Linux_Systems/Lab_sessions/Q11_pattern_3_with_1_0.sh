#! /bin/bash

read -p "Enter the number of rows: " n

for row in `seq $n`
do
    for space in `seq $(($n - $row))`
    do
	echo -n " "
    done
    for digit in `seq $row`
    do
	echo -n "$(($digit % 2))"
    done
   
    echo "" 

done

