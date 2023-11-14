#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 20-04-2022
Description: Write a script to print the length of each and every string using arrays    


Sample execution: -

Test Case 1:
./string_length.sh hello hai how are you?
Length of string (hello) - 5
Length of string (hai) - 3
Length of string (how) - 3
Length of string (are) - 3
Length of string (you?) - 4

Test Case 2:
./string_length.sh
Error : Please pass the arguments through command-line.


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]								#condition to check if no CLAs are passed
then
    echo "Error : Please pass the arguments through command-line."
else
    array=($@)								#storing all the CLAs in an array 
    
    for i in `seq 0 $(( ${#array[@]}-1))`				#for loop to access the array elements
    do
	
	echo "Length of string (${array[$i]}) - ${#array[$i]}"		#printing the length of array elements

    done
fi

   
