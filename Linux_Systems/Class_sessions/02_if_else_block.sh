#! /bin/bash

read -p "Enter two numbers: " len brd

if [ $len -gt 0 ]
then
    if [ $brd -gt 0 ]
    then

	if [ $len -eq $brd ]
	then
	    echo "The input numbers $len and $brd are sides of a square"

	else

 	   echo "The input numbers $len and $brd are sides of a rectangle"
	fi
    else
	echo "Invalid Input!!"
    fi
else
    echo "Invalid Input!!"
fi
