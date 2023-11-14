
#! /bin/bash

<<comment
factorial of n numbers
comment

read -p "Enter the value: " n
fact=1
i=1
while [ $i -le $n ]			 
do
    fact=$(($fact * $i))
    i=$(($i+1))
done
echo "The factorial is: $fact "

