#! /bin/bash

read -p "Enter an input: " var

str1=Hello

case $var in
    	100)
	    echo "You entered numer 100"
	    ;;
	-4.5)
	    echo "You entered number -4.5"
	    ;;
	Emertxe)
	    echo "The entered sting is Emertxe"
	    ;;
	$srt1)
	    echo "The entered string is Hello"
	    ;;
	'w')
	    echo "The entered character is w"
	    ;;
	100)
	    echo "duplicate 100"
	    ;;
	 *)
	     echo "Invalid input!!"
esac
	
