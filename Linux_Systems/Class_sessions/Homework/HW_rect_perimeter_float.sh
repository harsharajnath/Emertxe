#!/bin/bash

read -p "Enter Sides of Rectangle: " len brdth
temp1=$(echo "$len > 0" | bc)
temp2=$(echo "$brdth > 0" | bc)

if [ $temp1 -eq 1 ]
then
    if [ $temp2 -eq 1 ]
    then
        echo "The perimeter of the Rectangle is: "
        echo "2 * ($len + $brdth)" | bc
    else
        echo "Invalid input !!"
    fi
else 
    echo "Invalid input !!"
fi

