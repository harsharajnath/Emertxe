#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 29-04-22
Description: Write a script to replace 20% lines in a C file randomly and replace it with the pattern

Sample execution: -

1. ./replace_DEL.sh main.c
Before replacing
#incude <stdio.h>
int main()
{
	 printf(“Hello world\n”);
     }
After replacing
#incude <stdio.h>
int main()
{
<-----------Deleted------------>
}

2. ./replace_DEL.sh main1.c
Error : No such a file.

3. ./replace_DEL.sh main2.c
Error : main2.c is empty file. So can’t replace the string.

4. ./replace_DEL.sh
Error : Please pass the file name through command line.


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]									#condition to check if no CLA is passed
then
    echo "Error : Please pass the file name through command line."
elif [ $# -gt 1 ]								#condition to check if more than one CLA is passed
then
    echo "Please provide only one file"
elif [ $# -eq 1 ]								#condition to check if exactly one CLA is passed
then
    if [ -f $1 ]								#checking if file exist or not
    then
	if [ -s $1 ]								#checking if file has content or not
	then
	    totallines=`wc -l $1 | cut -d " " -f 1`					#counting total number of lines in the file
	    twentypercentoflines=`echo "$totallines * 20/100" | bc`			#counting 20 % of total number of lines

	    if [ $totallines -ge 5 ]							#condition to check if atleast 5 lines are present inside the fie
	    then									#because we need atleast 5 lines to replace atleast one line

		randomline=(`shuf -i 1-$totallines | head -$twentypercentoflines`)		#generating random line numbers to replace
		count=0										#initilizing count to 0
		for i in ${randomline[@]}
		do
		    if [ $count -ne $((${#randomline[@]}-1)) ]				#condition to replace 1st random line till 2nd last random line
		    then
			sed -i ''$i's/.*/<-----------Deleted------------>/' $1		#replacing lines inplace
			count=$(($count + 1))						#incrementing count by 1

		    elif [ $count -eq $((${#randomline[@]}-1)) ]			#condition to replace last random line
		    then
			sed -i ''$i's/.*/<-----------Deleted------------>/' $1		#replacing last line inplace
			sed ''$i's/.*/<-----------Deleted------------>/' $1		#replaced line showing in terminal
		    fi

		done
	    else
		echo "File must have atleast 5 lines inside it."

	    fi
	else
	    echo "$1 is empty file. So can’t replace the string."
	fi
    else
	echo "Error : No such a file."
    fi
fi
