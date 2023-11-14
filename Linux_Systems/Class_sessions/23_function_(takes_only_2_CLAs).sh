#! /bin/bash

if [ $# -ge 4 ]
then
	function find_sum()
	{
		echo "$1 + $2" | bc
	}

echo "The sum is `find_sum 12.5 -5`"		#output is 7.5

res=$(find_sum 10 -2.5 15.5 $2 $4)		

echo "The result is $res"			#output is 7.5

echo "The sum of all CLAs `find_sum $@`"	#output is sum of 1st two CLAs


else
    echo "No CLAs are passed!!"
fi
