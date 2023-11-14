#! /bin/bash

<<comment
Generate n Fibonacci terms
comment

read -p "How many terms in Fibonacci Series: " input

count=1

first=0
second=1
next=0
while [ $count -le $input ]
do
    echo -n "$next "
    first=$second
    second=$next
    next=$(($first + $second))
    count=$(($count + 1))
done
