#! /bin/bash

read -p "Enter the string: " str

if [ -z $str ]
then
    echo "The entered string is empty"
else
    echo "The entered string is non-empty"
fi
