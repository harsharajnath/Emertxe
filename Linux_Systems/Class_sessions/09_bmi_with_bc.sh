#! /bin/bash

read -p "Enter height and weight: " height weight

bmi=`echo "scale=2; $weight / ( $height * $height )" | bc`

echo "BMI is: $bmi "

 if [ `echo "$bmi < 18.5" | bc` -eq 1 ]
 then
     echo "You are underweight"
 elif [ `echo "$bmi >= 18.5" | bc` -eq 1 -a `echo "$bmi <= 25" | bc` -eq 1 ]
 then
     echo "Your weight is normal"
 elif [ `echo "$bmi >= 25" | bc` -eq 1 -a `echo "$bmi < 30" | bc` -eq 1 ]
 then
     echo "You are overweight"
 else
     echo "You are obese"
 fi

