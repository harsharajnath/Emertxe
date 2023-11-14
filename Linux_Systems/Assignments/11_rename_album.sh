#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 26-04-22
Description: Given album name and corresponding directory, this scripts renames the jpg files with new name passed through command line


Sample execution: -

Before executing the script
$ ls
DSN001.jpg DSN002.jpg DSN003.jpg DSN004.jpg DSN005.jpg

1) ./rename_album.sh day_out
All .jpg files in current directory is renamed as
day_out001.jpg day_out002.jpg day_out003.jpg day_out005.jpg day_out004.jpg

2) ./rename_album.sh
Error : Please pass the prefix name through command line.


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]				#condition to check if no CLA is passed
then
    echo "Error : Please pass the prefix name through command line."

elif [ $# -eq 1 ]			#condition to check if one CLA is passed
then
    prefix=$1				#prefix name is stored in prefix variable
    
    extension=".jpg"			#file extension is stored in extension variable
    
    oldname=(`ls *.jpg`)		#storing all the .jpg file names in an array

    for i in ${oldname[@]}		#for loop to treverse through the array
    do
	index=`echo $i | tr -d -c [:digit:]`	#extracting the indexing digit from the old file name
	newname="$prefix$index$extension"	#syntax of new name
	mv $i $newname				#renaming
    done
    echo "All .jpg files in current directory is renamed as"
    ls *.jpg					#listing all .jpg files after renaming

elif [ $# -gt 1 ]				#condition to check if more than one CLAs are passed
then
   echo "Error : Please enter only one prefix name"
fi
