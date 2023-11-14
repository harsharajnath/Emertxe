#! /bin/bash
 
#Name: Harsharaj Nath
#Date of Submission: 19-04-2022
#Description: Write a script to print chess board    


for row in `seq 8`
do
    for col in `seq 8`
    do
	if [ $((($row + $col + 1) % 2)) -eq 1 ]
	then
	    echo -n "1"
	else
	    echo -n "0"
	fi
    done
    echo ""
done
