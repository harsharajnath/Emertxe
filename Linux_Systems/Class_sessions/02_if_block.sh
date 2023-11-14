#! /bin/bash

read -p "Enter two numbers: " len brd

if [ $len -eq $brd ]
then
    echo "The input numbers $len and $brd are sides of a square"
fi

