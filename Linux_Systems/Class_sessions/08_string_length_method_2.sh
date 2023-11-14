#! /bin/bash

read -p "Enter the string: " str

if [ -n "$str" ]
then
    echo "The entered string is non- empty"
else
    echo "The entered string is empty"
fi
