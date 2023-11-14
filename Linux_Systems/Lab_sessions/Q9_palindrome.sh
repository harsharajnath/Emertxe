#! /bin/bash

read -p "Enter the number: " num

value=$num
reverse=0

while [ $num -ne 0 ]
do
	remainder=$num%10				#to extract last digit
	
	num=$(($num/10))				#update num with omitted last digit

	reverse=$(($reverse * 10 + $remainder))		#getting the reverse
    done

if [ $reverse -eq $value ]
then
    echo "The number is palindrome"
else
    echo "The number is not a palindrome"
fi
