#! /bin/bash

read -p "Enter the number of rows: " n


prev_val=0
sum=1


for row in `seq $n`
do
    for col in `seq $row`
    do

	echo -n "$sum "

	sum=$(($sum + $prev_val))

	prev_val=$(($sum - $prev_val))

    done
    echo "" 

done

