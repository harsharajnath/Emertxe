#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 21-04-2022
Description: Script to print contents of file from given line number to next given number of lines.


Assume, Contents of myfile.txt is

line number 1
line number 2
line number 3
line number 4
line number 5
line number 6
line number 7
line number 8
line number 9
line number 10

Sample execution: -

1. ./print_lines.sh 5 3 myfile.txt
line number 5
line number 6
line number 7

2. ./print_lines.sh myfile.txt
Error: arguments missing!
Usage: ./file_filter.sh start_line upto_line filename
For eg. ./file_filter.sh 5 5 <file>

3. ./print_lines.sh 5 10 myfile.txt
Error: data.txt is having only 10 lines. file should have atleast 14 lines


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]					#condition to check if no CLAs are passed
then
    echo "Error: No arguments passed"


elif [ $# -lt 3 ]				#conditon to check if any CLA is missing				
then
    echo "Error: arguments missing!"
    echo "Usage: ./file_filter.sh start_line upto_line filename"
    echo "For eg. ./file_filter.sh 5 5 <file>"


elif [ $# -gt 3 ]				#condition to check for invalid number of CLAs passed
then
    echo "Error: Unexpected number of arguments passed"
    echo "Usage: ./file_filter.sh start_line upto_line filename"
    echo "For eg. ./file_filter.sh 5 5 <file>"


elif [ $# -eq 3 ]				#conditon to check if 3 CLAs are passed
then
    numoflines=`cat $3 | wc -l`			#stores the value of number of lines inside the input file

    if [ $(($1 + $2 - 1 )) -gt $numoflines ]		#condition to check if there is required number of lines in the input file
    then
	echo "Error: $3 is having only $numoflines lines. file should have atleast $(($1 + $2 - 1)) lines"
    else
	head -$(($1 + $2 - 1)) $3 | tail -$2		#logic to print required number of lines
    fi
fi

