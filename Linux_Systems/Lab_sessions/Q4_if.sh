#! /bin/bash

<<comment
WAP to check whether given year is leap year or not.
comment

read -p "Enter the year: " year
if [ $(($year % 100 )) -eq 0 ]
    then
	echo "Year is century year"
	if [ $(($year % 400 )) -eq 0 ]
	then
	    echo "This is a leap year"
	else
	    echo " This is not a leap year"

	fi
    else
	echo "Year is non-century year"
	if [ $(($year % 4 )) -eq 0 ]
	    then
		echo "This is a leap year"
	    else
		echo "This is not a leap year"
	    fi
	fi
