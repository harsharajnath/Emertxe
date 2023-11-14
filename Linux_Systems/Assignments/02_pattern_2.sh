#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 17-04-2022
Description: Read 'n' and generate a pattern given below(number increasing from Top to bottom)    


Sample Input:

Enter the number : 4

Sample Output:
1
2 3
4 5 6
7 8 9 10


documentation


#########################################_Script_begins_from_here_#########################################


read -p "Enter the number : " num		#taking number of lines from user 

prev=0						#initializing previous value with 0

for row in `seq $num`				#for loop for printing rows
do
   for col in `seq $row`			#for loop for printing columns
   do
       echo -n " $(( $prev + 1 )) "		
       prev=$(( $prev + 1 ))			#logic
   done						
   echo ""
done

