#! /bin/bash


if [ $# -ge 1 ]
then

	echo "The file name is $0
	The 1st CLA is $1
	All the CLAs $@
	Total number of CLAs $#"
    else
	echo "Insufficient number of arguments!!"
    fi
