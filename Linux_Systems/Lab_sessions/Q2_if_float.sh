#! /bin/bash

<<comment
WAP to check whether the entered number is multiple of 5.
comment

read -p "Enter a number: " num
if [ `echo "$num % 5" == 0 | bc` -eq 1 ]
then
    echo "The entered number is a multiple of 5"
else
    echo " The entered number is not a multiple of 5"
fi
