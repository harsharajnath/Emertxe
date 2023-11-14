#! /bin/bash

read -p "Enter Marks in Subject 1, Subject 2 and Subject 3 respectively: " sub1 sub2 sub3
total=$( echo "$sub1 + $sub2 + $sub3" | bc)
echo "Total Marks Obtained: $total "
temp1=$(echo "$total<50" | bc)
temp2=$(echo "$total>200" | bc)
if [ $temp1 -eq 1 ]
then
    echo "Fail"
elif [ $temp2 -eq 1 ]
then
    echo "Excellent"
else
    echo "Average"
fi
