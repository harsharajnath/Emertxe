#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 26-04-22
Description: Write script called say_hello, which will print greetings based on time


Sample execution: -

1. When we start shell (whenever you opening new tab or terminal)
Good Morning user, Have nice day!
This is Thursday 08 in June of 2017 (10:44:10 AM)


documentation


#########################################_Script_begins_from_here_#########################################

day_num=`date | cut -d " " -f3`			#extracting day in number

day=`date +%A`					#name of the day

month=`date +%B`				#name of the month

year=`date | cut -d " " -f6`			#extracting year

time_12hr=`date +%r | tr -cd [:digit:]:`	#extracting time in hh:mm:ss

user=`whoami`					#username

hr=`date +%H`					#extracting hour value

AM_PM=`date +%r | tr -cd [:digit:]:AMPM" " | tr [:space:] : | cut -d ":" -f4`		#extracting AM or PM

if [ $hr -ge 5 -a $hr -lt 12 ]			#checking time between 5 AM and 12 PM
then
	greeting="Good Morning"

elif [ $hr -eq 12 -o $hr -eq 13 ]		#checking time between 12 PM and 1 PM
then
	 greeting="Good Noon"

elif [ $hr -ge 14 -a $hr -lt 17 ]		#checking time between 2 PM and 5 PM
then
	 greeting="Good Afternoon"
	    
elif [ $hr -ge 17 -a $hr -lt 21 ]		#checking time between 5PM and 9 PM
then
	 greeting="Good Evening"

elif [ $hr -ge 21 -a $hr -lt 24 ]		#checking time between 9 PM to 12 AM		
then
	 greeting="Good Night"

elif [ $hr -eq 00 -a $hr -lt 5 ]		#checking time between 12 AM to 5 AM
then
	 greeting="Good Night"
fi

echo "$greeting $user, Have a nice day!"
echo "This is $day $day_num in $month of $year ($time_12hr $AM_PM)"
