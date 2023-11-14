#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 29-04-22
Description: Use a recursive function to print each argument passed to the function


Sample execution: -

Test Case 1:
./recursion.sh How are you? I am fine
How
are
you?
I
am
fine

Test Case 2: 
./recursion.sh
Error : Pass the arguments through command line.

Test Case 3:
./recursion.sh 1 12 123 1234 12345 123456
1
12
123
1234
12345
123456


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]					#checking if no CLA is passed
then
    echo "Error : Pass the arguments through command line."
else    
    function print()				#function definition
    {
	array=($@)				#storing all CLAs in an array
	if [ ${#array[@]} -ne 0 ]		#condition to stop the infinite loop
	then
	    echo $1				#using echo $1 only one time
	    array=${array[@]: 1: }		#offsetting 1st position of array after every function call
	    print ${array[@]}			#function calling itself	
	fi
    }

    array=($@)					#storing all CLAs in an array
    print ${array[@]}				#calling the function and passing the array as argument
fi
