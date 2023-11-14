#! /bin/bash

read -p "Enter a number: " num
temp=$num
sum=0

if [ $num -lt 0 ]
then
    num=$(($num * (-1)))
fi

while [ $num -ne 0 ]
do
    rem=$(($num % 10))
    sum=$(($sum + $rem))
    num=$(($num / 10))
done

echo  "The sum of digits of $temp is $sum"

