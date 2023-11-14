#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 20-04-2022
Description: Write a script to print chess board    


Sample Input: N/A

Sample Output: This script will print a chess board.


documentation


#########################################_Script_begins_from_here_#########################################


for row in `seq 8`					#for loop for printing rows		
do
    for col in `seq 8`					#for loop for printing columns
    do
	if [ $((($row + $col + 1) % 2)) -eq 1 ]		#logic
	then
	    echo -e -n "\e[47m" " "			#color code for white
	else
	    echo -e -n "\e[40m" " "			#color code for black
	fi
	if [ $col -ge 8 ]				
	then
	    echo -e -n "\e[0m" " "			#to make color normal
	fi				      	    
    done
    echo " "						#newline after every 8th column
done
