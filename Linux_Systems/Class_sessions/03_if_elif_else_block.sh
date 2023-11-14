#! /bin/bash

read -p "Enter the number: " num

if [ $num -lt 100 ]
then
    echo "The number $num is less than 100"
elif [ $num -gt 200 ]
then
    echo "The number $num is greater than 200"
else
    echo "The number is between 100 and 200"
fi

