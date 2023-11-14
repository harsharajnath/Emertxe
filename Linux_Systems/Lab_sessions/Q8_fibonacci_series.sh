#! /bin/bash

<<comment
Fibonacci series until  nth terms
comment

read -p "Enter the nth term: " n
first=0
second=1
next=0
while [ $next -le $n ]
do
    echo -n "$next "
    first=$second
    second=$next
    next=$(($first + $second))
done
