#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 17-04-2022
Description: Read 'n' and generate a pattern given below(number increments from left to right)


Sample Input:

Enter the number : 4

Sample Output:
1
1 2
1 2 3
1 2 3 4


documentation


#########################################_Script_begins_from_here_#########################################


read -p "Enter the number : " num		#taking number of lines from user

for row in `seq $num`				#for loop for printing rows
do
   for col in `seq $row`			#for loop for printing columns
   do
      echo -n "$col "				#logic
   done
   echo ""
done

