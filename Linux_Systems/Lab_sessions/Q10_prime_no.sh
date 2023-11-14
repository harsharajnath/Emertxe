#! /bin/bash

read -p "Enter a number: " num

numby2=$(($num/2))
if [ $num -gt 1 ]
then
    if [ $num -eq 2 ]
    then
	echo "$num is a Prime number"
    elif [ $num -gt 2 ]
    then
	flag=0
	for i in `seq 2 $numby2`
	do
	    numbyi=$(($num % $i))

	    if [ $numbyi -eq 0 ]
	    then
		flag=1
		break
	    fi
	done
	if [ $flag -eq 1 ]
	then
	    echo "$num is a not a Prime number"
	elif [ $flag -eq 0 ]
	then
	    echo "$num is a Prime number"
	fi
    fi
else
    echo "Please enter a number greater than 1!!"
fi
