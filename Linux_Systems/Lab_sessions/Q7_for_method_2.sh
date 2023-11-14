#! /bin/bash

<<comment
WAP to print all the even numbers from 1 to 100.
comment

echo "Program to print all the even numbers from 1 to 100"
for i in `seq 100`
do
    if [ $(( $i % 2 )) -eq 0 ]
    then
    	echo "$i"
    fi
done
