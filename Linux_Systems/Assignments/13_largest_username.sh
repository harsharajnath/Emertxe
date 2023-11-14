#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 29-04-22
Description: Display the longest and shortest user-names on the system


Sample execution: -
Test Case 1. 
./largest_username.sh 
The Longest Name is: speech-dispatcher
The Shortest Name is:lp
(Output might vary for each system)


documentation


#########################################_Script_begins_from_here_#########################################


array=(`cat /etc/passwd | cut -d ":" -f1`)		#extracting usernames and storing them to an array	


longest=${#array[0]}					#initializing 1st element of array as longest

shortest=${#array[0]}					#initializing 1st element of array as shortest

for i in `seq 0 $((${#array[@]}-1))`			
do
    if [ ${#array[i]} -gt $longest ]			#checking if current array element is longer than value of longest
    then
	longest=${#array[i]}				#updating longest with current array element
	longestusername=${array[i]}			#storing the longest user name
    fi
done
echo "The Longest Name is: "$longestusername			#printing longest username


for i in `seq 0 $((${#array[@]}-1))`
do
    if [ ${#array[i]} -lt $shortest ]			#checking if current array element is shorter than value of shortest
    then
	shortest=${#array[i]}				#updating shortest with current array element
	shortestusername=${array[i]}			#storing the shortest user name
    fi
done

echo "The Shortest Name is: "$shortestusername			#printing longest username
