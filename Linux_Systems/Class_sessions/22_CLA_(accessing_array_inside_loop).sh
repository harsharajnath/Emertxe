#!/bin/bash

if [ $# -ge 4 ]
then

arr=($@)

echo "All the CLAs are ${arr[@]}

All the CLAs are ${arr[*]}
All the CLAs are $@

Total number of CLAs: ${#arr[@]}
Total number of CLAs: ${#arr[*]}
Total number of CLAs: $#

1st CLA: ${arr}
1st CLA: ${arr[0]}
1st CLA: $1

Length of 1st CLA: ${#arr}

4th CLA: ${arr[3]}

Length of 4th CLA: ${#arr[3]}

The last CLA: ${arr[-1]}
The last CLA: ${arr[${#arr[@]}-1]}
The last CLA: ${arr[$# - 1]}

Length of last CLA: ${#arr[-1]}"

echo


for i in $@				#method 1
do
	echo "$i "
done

echo

for i in ${arr[@]}			#method 2
do
    echo "$i "
done


echo

for i in `seq 0 $((${#arr[@]} - 1))`	#method 3
do
    echo "${arr[$i]}"
done

echo

for i in `seq 0 $(($# -1))`		#method 4
do
    echo "${arr[$i]}"
done


else
    echo "Minimum of 4 CLAs are to be passed."
fi
