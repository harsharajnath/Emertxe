#! /bin/bash

read -p "enter m and n: " m n
sum=0
for i in `seq $m $n`
do
    sum=$(($sum + $i))
done
echo sum is $sum
