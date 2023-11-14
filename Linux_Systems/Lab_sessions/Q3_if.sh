#! /bin/bash

<<comment
WAP, given three sides of a triangle, to check whether the triangle is perfect right triangle
.
comment

read -p "Enter 3 sides of Triange: " side1 side2 side3

#condition1=$(( $side1 * $side1 )) -eq $(((($side2 * $side2) + ($side3 * $side3))))
#echo $condition1

if [ $(($side1 * $side1)) -eq $((($side2 * $side2) + ($side3 * $side3))) ]
then
    echo "The Triangle is a perfect right triange."
elif [ $(($side2 * $side2)) -eq $((($side1 * $side1) + ($side3 * $side3))) ]
then
    echo "The Triangle is a perfect right triange."
elif [ $(($side3 * $side3)) -eq $((($side2 * $side2) + ($side1 * $side1))) ]
then
    echo "The Triangle is a perfect right triange."
else
    echo "The Triangle is not a perfect right triange."
fi
