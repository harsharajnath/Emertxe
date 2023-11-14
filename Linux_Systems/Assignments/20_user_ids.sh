#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 29-04-22
Description: Count the number of users with user IDs between given range.


Sample execution: -
1. ./user_ids.sh
Total count of user ID between 500 to 10000 is: 2

2. ./user_ids.sh 0 100
Total count of user ID between 0 to 100 is : 3

3. ./user_ids.sh 100
Error : Please pass 2 arguments through CL.
Usage : ./user_ids.sh 100 200

4. ./user_ids.sh 200 100
Error : Invalid range. Please enter the valid range through CL.


documentation


#########################################_Script_begins_from_here_#########################################


alluserids=(`cat /etc/passwd | cut -d ":" -f3`)			#storing all the user ids in an array

if [ $# -eq 0 ]							#condition to check if no CLA is passed
then
    count=0							#initializing count to 0
    for i in `seq 0 $((${#alluserids[@]}-1))`
    do
	if [ ${alluserids[i]} -ge 500 -a ${alluserids[i]} -le 10000 ]		#condition to check if user id is between 500 and 10000
	then
	    count=$(( $count + 1 ))						#increment count by 1
	fi
    done

    echo "Total count of user ID between 500 to 10000 is: "$count		#display the count of user IDs

elif [ $# -eq 1 -o $# -gt 2 ]					#condition to check if only 1 or more than 2 CLAs are passed
then
    echo "Error : Please pass 2 arguments through CL."
    echo "Usage : ./user_ids.sh 100 200"

elif [ $# -eq 2 ]						#condtion to check if exactly 2 CLAs are passed
then
    if [ $1 -le $2 ]						#condition to check if the lower limit is less than the upper limit
    then
	count=0							#intilializing count to 0
	for i in `seq 0 $((${#alluserids[@]}-1))`
	do
	    if [ ${alluserids[i]} -ge $1 -a ${alluserids[i]} -le $2 ]		#condition to check if user id is between lower limit and upper limit
	    then
		count=$(( $count + 1 ))						#increment count by 1
	    fi
	done

	echo "Total count of user ID between $1 to $2 is: "$count		#display the count of user IDs

    else
	echo "Error : Invalid range. Please enter the valid range through CL."
    fi
fi
