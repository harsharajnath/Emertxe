#! /bin/bash

read -p "Enter the number of rows: " n

for row in `seq $n`
do
    for space in `seq $(($row - 1))`
    do
	echo -n " "
    done
    for star in `seq $(($n - $row + 1))`
    do
	echo -n "*"
    done
    echo "" 
done

