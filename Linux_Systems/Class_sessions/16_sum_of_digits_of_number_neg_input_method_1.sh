#! /bin/bash

read -p "Enter a number: " num
temp=$num
sum=0

while [ $num -ne 0 ]
do
    rem=$(($num % 10))
    sum=$(($sum + $rem))
    num=$(($num / 10))
done
if [ $sum -lt 0 ]
then
    sum=$(($sum * (-1)))
fi
echo  "The sum of digits of $temp is $sum"

