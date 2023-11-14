#! /bin/bash

<<comment
WAP that reads in 2 integers and determines and prints if the first is a multiple of the second.
comment

read -p "Enter two integer: " num1 num2

if [ $num1 -gt $num2 ]
then
	if [ $(($num1 % $num2)) -eq 0 ]
	then
    		echo "Frist number is multiple of second number"
	else
    		echo "First number is not a multiple of second number"
	fi
    else
	echo "Please enter first number greater than second number"
    fi
