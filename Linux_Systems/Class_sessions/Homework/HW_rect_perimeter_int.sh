#!/bin/bash

read -p "Enter Sides of Rectangle: " len brdth

if [ $len -gt 0 ]
then
    if [ $brdth -gt 0 ]
    then
	echo -n  "The perimeter of the Rectange is: "
        echo "2 * ($len + $brdth)" | bc    
    else
	echo "Please enter valid input !!"
    fi
else
    echo "Please enter valid input !!"
fi

