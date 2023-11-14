#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 26-04-22
Description: Write a script to delete empty lines from a file

Contents of file.txt: (blank lines with multiple spaces)

Hello

         

How

               

are



you?

Sample execution: -

1. ./delete_empty_lines.sh file.txt
Empty lines are deleted
Hello
How
are
you?

2. ./delete_empty_lines.sh
Error: Please pass the file name through command line.


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]						#condition to check if no CLA is passed
then
    echo "Error: Please pass the file name through command line."
elif [ $# -eq 1 ]					#condition to check if one CLA is passed
then
	if [ -f $1 ]					#check if file or not
	then
	    if [ -s $1 ]				#check if file has content or not
	    then
		echo "Empty lines are deleted"		
		sed '/^[[:space:]]*$/d' $1		#deleting empty lines (display in standard output)
		sed -i '/^[[:space:]]*$/d' $1		#deleting in-place
	    else
		echo "Error: File is empty"
	    fi
	else
	    echo "Error: Not a valid file"
	fi
elif [ $# -gt 1 ]					#condition to check if more than one CLA is passed
then
    echo "Error: Please enter a single file name"
fi

