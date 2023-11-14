#!/bin/bash

arr=(blue red green yellow purple white black)

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
