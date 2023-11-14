#! /bin/bash

read -p "Enter the string: " str

str1=world

if [ $str = Hello ]
then
    echo "The entered string is Hello"
elif [ "$str" = "Emertxe" ]
then
    echo "The entered string is Emertxe"
elif [ ${str} = 'Happy' ]
then
    echo "The entered string is Happy"
elif [ $str = $str1 ]
then
    echo "The entered string is world"
else
    echo "Invalid input!!"
fi

