#! /bin/bash

for row in `seq 1`
do
    for col in `seq 11`
    do
	echo -n "*"
    done

    echo ""
    
    for star in `seq 6`
    do
	echo "*    *"
    done

    for col in `seq 11`
    do
	echo -n "*"
    done

    echo ""
done
