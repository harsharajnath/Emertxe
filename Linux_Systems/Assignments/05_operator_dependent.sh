#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 25-04-22
Description: Write a script to perform arithmetic operation on digits of a given number


Sample execution: -

Test Case 1:
./operator_dependent.sh 1234+
Sum of digits = 10

Test Case 2: 
./operator_dependent.sh 8312-
Subtraction of digits = 2

Test Case 3:
./operator_dependent.sh 5487
Error: Operator missing or invalid operator, please pass operator as last digit (+,-,x,/)

Test Case 4: 
./operator_dependent.sh 1111x
Multiplication of digits = 1

Test case 5:
./operator_dependent.sh 12/
Division of digits = .50

Test Case 6: 
./operator_dependent.sh
Error : Please pass the arguments through CL.
Usage : ./operator_dependent.sh 2345+


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]								#condition to check if no CLA is passed
then
    echo "Error : Please pass the arguments through CL."
    echo "Usage : ./operator_dependent.sh 2345+"


elif [ $# -eq 1 ]							#condition to check if one CLA is passed
then

    var=$1								#assigning value of CLA to a variable
    operator=${var: -1} 						#extracting the operator
    numlength=$((${#var}-1))						#length of digit sequence
        
    case $operator in
			
	+)									#case statement for Addition
	    		sum=0							#initializing sum variable with 0
	    		for i in `seq 0 $(($numlength-1))`
			do
				digit=${var:$i:1}				#extracting the digits one by one from digit sequence
				sum=$(($digit+$sum))				#addition operation
			done
				echo "Sum of digits = $sum"			#printing the result	
			;;
	
		    -)								#case statement for Subtraction
			sub=0							#initializing sub variable with o
			for i in `seq 0 $(($numlength-1))`
			do  
			    	digit=${var:$i:1}				#exracting the digits one by one from the digit sequence
				sub=$(($sub-$digit))				#subtraction operation
				if [ $i -eq 0 ]					#condition to check the 1st digit				
				then
				    sub=$((-sub))				#inverting the 1st digit to make it positive after being subtracted from 0
				fi
			done
				echo "Subtraction of digits = $sub"		#printing the result
			;;

		    x)								#case statement for Multiplication
			mul=1							
			for i in `seq 0 $(($numlength-1))`
			do
				digit=${var:$i:1}				#extracting the digits one by one from digit sequence
				mul=$(($digit * $mul))				#multiplication operation	
			done
				echo "Multiplication of digits = $mul"		#printing the result
			 
			;;

		    /)								#case statement for Division
			for i in `seq 0 $(($numlength-1))`		
			do
			    	digit=${var:$i:1}				#extracting the digits one by one from digit sequence
				if [ $i -eq 0 ]					#condition to check the 1st digit
				then
				    div=$(($digit * $digit))			#squaring the 1st digit so that after division also we get the digit itself
				fi
				div=`echo "scale=2; $div/$digit" | bc`		#division operation
				
			done
				echo "Division of digits = $div"		#printing the result
			;;

		    *)	echo "Error: Operator missing or invalid operator, please pass operator as last digit (+,-,x,/)"			#default statement
			;;
		esac
elif [ $# -gt 1 ]								#condition to check if more than one CLA is passed
then
    echo "Unexpected number of arguments"
    echo "Usage : ./operator_dependent.sh 2345+"
fi
