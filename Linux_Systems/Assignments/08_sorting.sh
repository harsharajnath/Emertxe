#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 22-04-2022
Description: Script to sort a given number in ascending or descending order


Sample execution: -

Test Case 1: 
./sorting.sh -a 5 4 6 2 3 8 9 7 1
Ascending order of array is 1 2 3 4 5 6 7 8 9

Test Case 2: 
./sorting.sh -d 5 4 6 2 3 8 9 7 1
Descending order of array is 9 8 7 6 5 4 3 2 1

Test Case 3:
./sorting.sh 5 4 6 2 3 8 9 7 1
Error : Please pass the choice.
Usage : ./sorting -a/-d 4 23 5 6 3

Test Case 4: 
./sorting.sh
Error : Please pass the argument through command line.
Usage : ./sorting -a/-d 4 23 5 6 3

Test Case 5:
./sorting.sh -d 5 4 6 2 -3 8 -9 7 1
Descending order of array is 8 7 6 5 4 2 1 -3 -9


documentation


#########################################_Script_begins_from_here_#########################################


if [ $# -eq 0 ]								#condition to check if no CLAs are passed
then
    echo "Error : Please pass the argument through command line."
    echo "Usage : ./sorting -a/-d 4 23 5 6 3"
elif [ $# -eq 1 ]							#condition to check if only one CLA is passed
then
    echo "Error : Please pass the argument through command line."
    echo "Usage : ./sorting -a/-d 4 23 5 6 3"
elif [ $# -ge 2 ]							#condition to check if atleast two CLAs are passed
then
    
    array=($@)								#storing all CLAs in array
    
    case $1 in										#case statements for ascending or decending order
		-a) 	for i in `seq 1 $((${#array[@]}-1))`				#array sorting in ascending order
			do 
				for j in `seq 1 $((${#array[@]}-$i-1))`			 
				do
					if [ ${array[$j]} -ge ${array[$(($j+1))]} ]
					then
	    					temp=${array[$j]}
	    					array[$j]=${array[$(($j+1))]}			#swap logic
	    					array[$(($j+1))]=$temp
					fi
    				done
			done

			echo -n "Ascending order of array is " 
		
			for i in `seq 1 $((${#array[@]}-1))`					#printing sorted array
			do
				echo -n "${array[$i]} "
		    	done
		    	echo ""
    		;;


		-d)	for i in `seq 1 $((${#array[@]}-1))`				#array sorting in descending order
			do 
				for j in `seq 1 $((${#array[@]}-$i-1))`
				do
					if [ ${array[$(($j+1))]} -ge ${array[$j]} ]
					then
	    					temp=${array[$j]}
	    					array[$j]=${array[$(($j+1))]}			#swap logic
	    					array[$(($j+1))]=$temp
					fi
    				done
			done

			echo -n "Descending order of array is " 
		
			for i in `seq 1 $((${#array[@]}-1))`					#printing sorted array
			do
				echo -n "${array[$i]} "
		    	done
		    	echo ""
	        ;;


		*)									#default case if no choice is passed
	    		echo "Error : Please pass the choice."
	    		echo "Usage : ./sorting -a/-d 4 23 5 6 3"
    esac
	
fi
