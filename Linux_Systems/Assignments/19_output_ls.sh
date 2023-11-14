#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 26-04-22
Description: WAS to print contents of a directory without ls command


Sample execution: -

Let assume your pwd is /home/user/ECEP/Linux_Systems/

1. ./output_ls.sh
Assignments Classwork

2. ./ouput_ls.sh ~ ~/ECEP
/home/user:
Downloads Documents Desktop Music Pictures Public Videos
ECEP
/home/user/ECEP:
Linux_Systems Advnc_C Linux_Internals Data_Structures MC

3. ./ouput_ls.sh Test
output_ls.sh: Cannot access ‘Test’ : No such a file or directory.


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]					#condition to check if no CLA is passed
then
    echo "Content of current directory:"
    echo *					#printing the content of current directory
    echo ""

elif [ $# -ge 1 ]				#condition to check if one or more CLAs are passed
then
    for i in $@					#for loop for traversing through all CLAs
    do
	if [ -e $i ]				#condition to check if directory is present or not
	then
	    cd $i				#if directory is present, change directory to the given directory
	    dir=`pwd`				#storing the present working direction in dir variable
	    echo "$dir:"			#printing the directory in the required format
	echo *					#printing the content of present working directory
	echo ""
	else
	    echo "Cannot access ‘$i’ : No such a file or directory."		#error message if entered directory is not present
	fi
    done
fi

