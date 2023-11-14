#! /bin/bash

read -p "Enter array elements: " -a array

echo "Array in original order: "
echo ${array[@]}

for i in `seq 0 $((${#array[@]}-1))`
do 
    for j in `seq 0 $((${#array[@]}-$i-2))`
    do
	if [ ${array[$j]} -ge ${array[$(($j+1))]} ]
	then
	    temp=${array[$j]}
	    array[$j]=${array[$(($j+1))]}
	    array[$(($j+1))]=$temp
	fi
    done
done

echo "Array in sorted order: "
echo ${array[*]}

