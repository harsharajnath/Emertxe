#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 29-04-22
Description: Use pipes or redirection to create an infinite feedback loop.


Sample execution: -

1. ./redirection.sh
Before loop file contents
Hai hello
After loop file contents
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
.
.
.


documentation


#########################################_Script_begins_from_here_#########################################


echo "Before loop file contents" > redirection.txt		#creating a file with content

echo "Hai Hello" >> redirection.txt				#appending

echo "After loop file contents" >> redirection.txt		#appending

echo "Hai Hello" >> redirection.txt				#appending

tail -f -n1 redirection.txt >> redirection.txt | tail -f -n1 redirection.txt		#using pipe and redirection to create an infinite feedback loop
