#! /bin/bash

<<comment
sum of n numbers
comment

read -p "Enter the value: " n
sum=0
i=1
while [ $i -le $n ]			 #n=5,  1+2+3+4+5
do
    sum=$(($sum+$i))
    i=$(($i+1))
done
echo "The sum of $n numbers is: $sum "

