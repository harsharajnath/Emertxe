#! /bin/bash

read -p "Enter 3 numbers: " num1 num2 num3

if [ $num1 -ge $num2 -a $num1 -ge $num3 ]
    then
	echo "$num1 is the largest"
elif [ $num2 -ge $num3 -a $num2 -ge $num1 ]
then
    echo "$num2 is the largest"
else
    echo "$num3 is the largest"
fi
