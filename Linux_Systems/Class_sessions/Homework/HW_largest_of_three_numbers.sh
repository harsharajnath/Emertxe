#! /bin/bash

read -p "Enter 3 numbers: " num1 num2 num3

if [ $num1 -gt $num2 ]
then
    if [ $num1 -gt $num3 ]
    then
	option="case1"
    else
	option="case2"
    fi
elif [ $num2 -gt $num3 ]
then
    option="case3"
else
    option="case4"
fi

case $option in
    case1)
	echo "$num1 is the largest"
	;;
    case2)
	echo "$num3 is the largest"
	;;
    case3)
	echo "$num2 is the largest"
	;;
    case4)
	echo "$num3 is the largest"
	;;
esac
