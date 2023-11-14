#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 26-04-22
Description: Shell script to convert string lower to upper and upper to lower


Sample execution: -

1. ./upper_lower.sh file.txt

1 – Lower to upper
2 – Upper to lower
Please select option : 1
WHAT IS OS?
WHAT ARE THE DIFFERENT OS?
WHEN IS OS USED?
WHAT IS PARTITION AND ITS USE?
HOW MANY PARTITIONS CAN BE DONE?

2. ./upper_lower.sh file.txt

1 – Lower to Upper
2 – Upper to Lower
Please select option : 2
what is os?
what are the different os?
when is os used?
what is partition and its use?
how many partitions can be done?

3. ./upper_lower.sh file1.txt

Error: No contents inside the file.

4. ./upper_lower.sh
Error : Please pass the file name through command line.


documentation

#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]									#condition to check if no CLA is passed
then
    echo "Error : Please pass the file name through command line."

elif [ $# -eq 1 ]								#condition to check if one CLA is passed
then
    if [ -f $1 ]								#condition to check if file exist or not
	then
	    if [ -s $1 ]							#condition to check if file has content or not
	    then
		echo "1 – Lower to Upper"
		echo "2 – Upper to Lower"
		read -p "Please select option : " option			#taking option from the user
		echo ""
		case $option in 						#case statements
		    		1)
				    cat $1 | tr [:lower:] [:upper:]		#translating from lower to upper
				    ;;
				2)
				    cat $1 | tr [:upper:] [:lower:]		#translating from upper to lower
				    ;;
				*)
				    echo "Please select proper option"		#default case if wrong option is passed
				    echo "1 – Lower to Upper"
				    echo "2 – Upper to Lower"
				    ;;
			    esac
	     else
		 echo "Error: No contents inside the file."
	    fi
       else
	   echo "File does not exist"
    fi
fi


