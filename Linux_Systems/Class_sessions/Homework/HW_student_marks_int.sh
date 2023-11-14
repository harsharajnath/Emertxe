#! /bin/bash

read -p "Enter Marks in Subject 1, Subject 2 and Subject 3 respectively: " sub1 sub2 sub3
total=$((sub1 + $sub2 + $sub3))
echo "Total Marks Obtained: $total"
if [ $total -lt  50 ]
then
    echo "Fail"
elif [ $total -gt  200 ]
then
    echo "Excellent"
else 
    echo "Average"
fi
