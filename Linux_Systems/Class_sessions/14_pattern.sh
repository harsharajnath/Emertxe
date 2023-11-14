#! /bin/bash

read -p "Enter the number of rows: " n

for row in `seq $n`
do 
    for col in `seq $row`
    do
	echo -n "* "
    done
    echo
done
