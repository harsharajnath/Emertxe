#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 20-04-2022
Description: Write a script for arithmetic calculator using command line arguments   


Sample execution: -

1. ./arithmatic_calc.sh 25 + 41
25 + 41 = 66

2. ./arithmatic_calc.sh 10 x 5
10 x 5 = 50

3. ./arithmatic_calc.sh 25 / 5
25 / 5 = 5.00

4. ./arithmatic_calc.sh 10.2 – 5.6
10.2 – 5.6 = 4.6

5. ./arithmatic_calc.sh
Error : Please pass the arguments through command line.
Usage:./arithmatic_calc.sh 2.3 + 6.7

6. ./arithmatic_calc.sh 3.4
Error:Please pass 3 arguments.
Usage:./arithmatic_calc.sh 2.3 + 6.7


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]								#condition to check if no CLAs are passed
then
    echo "Error : Please pass the arguments through command line."
    echo "Usage:./arithmatic_calc.sh 2.3 + 6.7"
elif [ $# -ne 3 ]							#condition to check if unexpected number of CLAs are passed other than 3
then
    echo "Error:Please pass 3 arguments."
    echo "Usage:./arithmatic_calc.sh 2.3 + 6.7"

elif [ $# -eq 3 ]							#condition to check if 3 CLAs are passed
then
    case $2 in								#case statements for evaluating various arithmetic operations
	+)
	    sum=`echo " $1 + $3 " | bc`					#addition
	    echo "$1 + $3 = $sum"
	    ;;
	x)
	    mul=`echo " $1 * $3 " | bc`					#multiplication
	    echo "$1 x $3 = $mul"
	    ;;
	/)
	    div=`echo "scale=2; $1 / $3 " | bc`				#division
	    echo "$1 / $3 = $div"
	    ;;
	-)
	    sub=`echo " $1 - $3 " | bc`					#subtraction
	    echo "$1 - $3 = $sub"
	    ;;
	*)
	    echo "Invalid Operator!!"					#default case - if unexpected operator is passed
	    echo "Please use any of the following operator + - x /"
    esac
fi

