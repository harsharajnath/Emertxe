#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 29-04-22
Description: For each directory in the $PATH, display the number of executable files in that directory


Sample execution: -

1. ./executable_path.sh
Current dir: /usr/local/sbin
current count: 0
Current dir: /usr/local/bin
current count: 0
Current dir: /usr/sbin
current count: 205
Current dir: /usr/bin
current count: 1889
Current dir: /sbin
current count: 187
Current dir: /bin
current count: 159
Current dir: /usr/games
current count: 5
Current dir: /usr/local/games
current count: 0
Total – 2445


documentation


#########################################_Script_begins_from_here_#########################################


directories=(`printenv PATH | tr ":" " "`)		#extracting directories from $PATH
totalcount=0						#initializing total count with 0
for i in ${directories[@]}
do
    if [ -d $i ]						#checking if directory present or not
    then
	echo "Current dir: $i"
	
	directory_content=(`ls $i`)			#storing content of selected directory into an array
	count=0						#initializing count with 0
	
	for j in ${directory_content[@]}
	do
	    if [ -f -a -x ]				#checking if file is present and if file is executable
	    then
		count=$(($count + 1 ))			#incrementing count by 1 every time an executable file is found
	    fi
	done
		echo "current count: $count"
    fi
		totalcount=$(($totalcount + $count ))		#calculating total count
done
echo "Total - $totalcount"
