#! /bin/bash

<<comment
WAS to check whether the product of two given numbers is odd or even.
comment

read -p "Enter two numbers: " num1 num2
prod=`echo " $num1 * $num2 " | bc`
echo "The product is $prod "
if [ `echo " $prod % 2 == 0 " | bc` -eq 1 ]
then
    echo "The product is even"
else
    echo "The product is odd"
fi
 
