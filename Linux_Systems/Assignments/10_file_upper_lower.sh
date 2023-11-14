#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 26-04-22
Description: Write a script to rename a file/directory replaced by lower/upper case letters


Sample execution: -

Before running the script

$ ls
File.txt MyScript.SH MyFile007.txt dir/ Assign1/ newfolder/

$ ./file_upper_lower.sh
Files are rename in lowercase and directories are renamed in upper case

$ ls
file.txt myfile007.txt myscript.sh DIR/ ASSIGN1/ NEWFOLDER/


documentation


#########################################_Script_begins_from_here_#########################################


echo "Files are rename in lowercase and directories are renamed in upper case"
echo ""
array=(`ls`)					#storing all the content of present working directory in an array

for i in ${array[@]}				#for loop for traversing through the array elements
do
    if [ -f  $i ]				#checking if file
    then
	newfilename=`echo $i | tr [A-Z] [a-z]`	#changing file name from upper case to lower case
	
	if [ $i != $newfilename ]		#condition for renaming, rename only if file name is not in lower case
	then
	    mv $i $newfilename			#renaming the file
	fi

    elif [ -d $i ]				#checking if directory
    then
	newdirname=`echo $i | tr [a-z] [A-Z]`   #changing directory name from lower case to upper case
	
	if [ $i != $newdirname ]		#condition for renaming, rename only if directory name is not in upper case
	then
	    mv $i $newdirname			#renaming the directory
    	fi
    fi
done

ls						#printing the content of present working directory
