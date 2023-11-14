#! /bin/bash

read -p "Enter range between which even numbers are to be displayed (excluding extreme ends): " m n
for i in `seq $(($m+1)) $(($n-1))`
do
    if [ $(($i % 2)) -eq 0 ]
    then
	echo $i
    fi
done
