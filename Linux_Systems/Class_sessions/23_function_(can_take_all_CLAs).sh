#! /bin/bash

if [ $# -ge 4 ]
then
	function find_sum()
	{	
	    sum=0
	    for i in $@
	    do
		sum=`echo "$sum + $i" | bc`
	    done
	    echo $sum
	}

echo "The sum is `find_sum 12.5 -5`"
res=$(find_sum 10 -2.5 15.5 $2 $4)
echo "The result is $res"
echo "The sum of all CLAs `find_sum $@`"
else
    echo "No CLAs are passed!!"
fi
