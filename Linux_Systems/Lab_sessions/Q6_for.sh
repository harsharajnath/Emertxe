#! /bin/bash

<<comment
WAP to find the smallest and largest of entered n numbers.
comment


read -p "Enter the range of inputs: " n
for i in `seq $n`
do
    echo "Enter the number: "
    read num
    if [ $i -eq 1 ]
    then
	small=$num
	large=$num
    fi
    
    if [ $num -lt $small ]
    then
	small=$num
    fi
    if [ $num -gt $large ]
    then
	large=$num
    fi
    
done

echo "The smallest number is: $small"
echo "The largest number is: $large"
