#! /bin/bash

read -p "Enter the number of rows: " n

for row in `seq $n`
do
    for space in `seq $row $(($n-1))`
    do
	echo -n " "
    done
    for star in `seq $row`
    do
	echo -n "* "
    done
    echo "" 
done

