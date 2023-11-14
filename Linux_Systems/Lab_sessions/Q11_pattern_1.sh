#! /bin/bash

read -p "Enter how many rows: " n

for row in `seq $n`
do
    for col in `seq $(($n - $row + 1))`
    do
	echo -n "*"
    done
    
    echo " "
done

