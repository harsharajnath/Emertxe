#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 29-04-22
Description: Write a script to determine whether a given file system or mount point is mounted


Sample execution: -

1. ./mounted_fs.sh /dev/sda2
File-system /dev/sda2 is mounted on / and it is having 98%
used space with 3298220 KB free.

2. ./mounted_fs.sh /dev
/dev is not mounted.

3. ./mounted_fs.sh
Error : Please pass the name of the file-system through command line.


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]							#checking if no CLA is passed
then
    echo "Error : Please pass the name of the file-system through command line."

elif [ $# -eq 1 ]						#checking if only one CLA is passed
then
    user_input=$1							#storing given file system or mount point in a variable

    filesys_mountpnt=(`df -h | tr -s " " | cut -d " " -f 1`)		#storing all File Systems and Mount points in an array
    available_space=(`df -h | tr -s " " | cut -d " " -f 4`)		#storing all available space data in an array
    usage_percentage=(`df -h | tr -s " " | cut -d " " -f 5`)		#storing all usage percentage data in an array
    mounted_on=(`df -h | tr -s " " | cut -d " " -f 6`)			#storing all mounted on data in an array
    flag=0								#initializing flag value to 0

    for i in `seq 1 $((${#filesys_mountpnt[@]}))`
    do
	if [ "${filesys_mountpnt[i]}" = "$user_input" ]			#checking if given file system is present in array or not
	then
	    echo "File-system $user_input is mounted on ${mounted_on[i]} and it is having ${usage_percentage[i]} used space with ${available_space[i]} free."
	    flag=1							#changing the flag value to 1
	fi
    done

    if [ $flag -eq 0 ]							#if given file system is not present
    then
	echo "$user_input is not mounted."
    fi

elif [ $# -gt 1 ]							#checking if more than one CLA is passed
then
    echo "Please enter only one File-system or mount point name."
fi
