#!/bin/bash


read -p "Enter the array length: " n

if [ $n -ge 4 ]
then
	declare -a arr

	echo "Enter the array elements: "

	for i in `seq 0 $(($n - 1))`
	do
    		read arr[$i]
	done


	echo "All the elements of array are ${arr[@]}

	All the elements of array are ${arr[*]}

	Array length: ${#arr[@]}

	Array length: ${#arr[*]}

	1st element of array: ${arr}

	1st element of array: ${arr[0]}

	Length of 1st element of array: ${#arr}

	4th element of array: ${arr[3]}

	Length of 4th element of array: ${#arr[3]}
	
	The last element of array: ${arr[-1]}

	The last element of array: ${arr[${#arr[@]}-1]}

	Length of last element of array: ${#arr[-1]}"

else
   	 echo "Insufficient number of elements!!"
fi

