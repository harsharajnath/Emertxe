#! /bin/bash

<<comment
WAP to check whether the entered number is multiple of 5.
comment

read -p "Enter a number: " num
if [ $(($num % 5)) -eq 0 ]
then
    echo "The entered number is a multiple of 5"
else
    echo " The entered number is not a multiple of 5"
fi
