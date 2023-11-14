#! /bin/bash

<<comment
WAP to check whether the product of two given numbers is odd or even.
comment

read -p "Enter two numbers: " num1 num2
prod=$(( num1 * num2 ))
echo "The product is $prod "
if [ $(($prod % 2)) -eq 0 ]
then
    echo "The product is even"
else
    echo "The product is odd"
fi 
