#! /bin/bash


<<documentation


Name: Harsharaj Nath
Batch ID: ECEP 22010
Date of Submission: 11-05-22
Description: Linux Systems Project - Command Line Test


documentation


#########################################_Script_begins_from_here_#########################################


echo "------------------------------------------------------------------"
echo -e "\e[96m                             Welcome\e[39m"
echo "------------------------------------------------------------------"
echo -e "\e[96m                       Command Line Test\e[39m"
echo "------------------------------------------------------------------"
echo ""

terminate=1												#to terminate after giving the test
while [ $terminate -eq 1 ]
do
    echo "Enter Your Choice:
    1. Sign Up
    2. Sign In
    3. Exit
    "

    read choice1


    if [ ! -e user.csv ]										#check if user.csv file exist or not, if not create one (1st time only)
    then
	echo "Contain usernames please DO NOT delete this file" > user.csv
    fi

    if [ ! -e password.csv ]
    then
	echo "Contain passwords please DO NOT delete this file" > password.csv				#check if password.csv file exist or not, if not create one (1st time only)
    fi

    case $choice1 in 											#primary case statement for Signup, Signin and exit
	1)												#Signup
	    echo ""
	    echo "You have entered --->  1. Sign Up"

	    user_name=(`cat user.csv`)									#storing usernames in an array
	    numberofusers=${#user_name[@]}								#counting no. of users

	    flag1=1											#flag for username
	    flag2=1											#flag for password

	    while [ $flag1 -eq 1 ]									
	    do
		echo ""
		read -p "Enter new username: " uname							#taking new username

		for i in `seq 1 $(($numberofusers - 1))`
		do
		    if [ $uname = ${user_name[$i]} ]							#checking if username already exist
		    then
			flag1=1
			break
		    else
			flag1=0
		    fi
		done
		if [ $flag1 = 0 ]
		then
		    echo "$uname" >> user.csv								#adding username to database
		elif [ $flag1 = 1 ]
		then
		    echo ""
		    echo "username already present, please try another username !!"			#error message if username already exist

		fi
	    done

	    while [ $flag2 -eq 1 ]
	    do
		echo  "Enter new password: "								#taking new password
		read -s pass_word1
		echo  "Confirm the password: "								
		read -s pass_word2

		if [ $pass_word1 = $pass_word2 ]							#checking if passwords are matching or not
		then
		    flag2=0
		else
		    flag2=1
		fi
		if [ $flag2 -eq 0 ]
		then
		    echo "$pass_word2" >> password.csv							#if matching, storing password to database
		    echo ""
		    echo "**Password Matched**"
		    echo ""
		    echo "Sign Up Successful !!"
		    echo "------------------------------------------------------------------"
		    echo ""
		elif [ $flag2 -eq 1 ]
		then
		    echo ""
		    echo "Password not matched, please try again !"
		    echo ""
		fi
	    done
	    ;;
	2)												#Signin
	    echo ""
	    echo "You have entered --->  2. Sign In"

	    user_name=(`cat user.csv`)									#storing usernames in an array
	    numberofusers=${#user_name[@]}								#counting no. of users
	    pass_word=(`cat password.csv`)								#storing passwords in an array

	    flag1=1											#flag for username
	    flag2=1											#flag for password
	    flag3=1											#flag for test

	    while [ $flag1 -eq 1 ]
	    do
		echo ""
		read -p "Enter username: " uname							#taking username

		for i in `seq 1 $(($numberofusers - 1))`
		do
		    if [ $uname = ${user_name[$i]} ]							#checking if the username exist in the database
		    then
			flag1=1
			break
		    else
			flag1=0
		    fi
		done
		if [ $flag1 = 0 ]
		then
		    echo ""
		    echo "username not found !"
		    echo "------------------------------------------------------------------"
		    echo ""
		elif [ $flag1 = 1 ]									#if username found, then taking the password
		then
		    while [ $flag2 -eq 1 ]
		    do
			echo  "Enter password: "
			read -s entered_password							#reading the password
			if [ $entered_password = ${pass_word[$i]} ]					#checking if password matches
			then
			    flag2=0
			else
			    flag2=1
			fi
			if [ $flag2 -eq 0 ]								#if password matches, proceeding to the test
			then
			    echo ""
			    echo "Sign In Successful !!"

			    while [ $flag3 -eq 1 ]										#test module
			    do
				echo "------------------------------------------------------------------"
				echo ""
				echo "1. Take Test"
				echo "2. Exit"
				echo ""
				echo "------------------------------------------------------------------"
				echo ""
				read choice2

				case $choice2 in										#case statements for taking the test or exit
				    1)  											#take test	
					clear 											#clearing screen for test
					for i in `seq 5 5 50`									#for loop to show 10 qns, each having 5 lines
					do
					    echo "************************** ALL THE BEST **************************"
					    echo ""
					    cat question_bank.txt | head -$i | tail -5						#reading questions and showing 1 question at a time
					    echo ""

					    for j in `seq 10 -1 1`								#for loop to read answer for 10 sec
					    do
						echo -e "\rEnter the choice: $j \c"						#to show countdown
						read -t 1  option								#taking the answer at an interval of 1 sec

						if [ -n "$option" ]								#checking if not empty
						then
						    break									#if not empty break
						else
						    option=e									#else store e in variable option
						fi
					    done
					    echo $option >> user_answer.txt							#storing answer in textfile
					    clear
					    if [ $i -eq 50 ]									#checking if last question
					    then
						flag4=0
					    fi

					done

					if [ $flag4 -eq 0 ]									#if last question display the message
					then
					    clear
					    echo "************************** TEST OVER **************************" >> result_view.txt	
					fi
					user_ans=(`cat user_answer.txt`)							#storing user answers in an array
					correct_ans=(`cat correct_answer.txt`)							#storing correct answers in an array
					ans_count=${#user_ans[@]}								#counting no. of user answers
					count=0											#to count no. of correct answers

					for i in `seq 0 $(($ans_count - 1))`
					do
					    if [ ${user_ans[$i]} = ${correct_ans[$i]} ]						#checking if user answer is correct
					    then
						echo "correct" >> result.txt

						count=$(($count + 1))								#incrementing count if answer is correct


					    elif [ ${user_ans[$i]} = e ]							#checking if timeout
					    then
						echo "timeout" >> result.txt
					    else
						echo "wrong" >> result.txt							#if above conditons does not satisfy
					    fi
					done

					echo "" >> result_view.txt
					echo "____________________________ RESULT ___________________________" >> result_view.txt
					echo "" >> result_view.txt

					k=0
					result=(`cat result.txt`)									#storing result in an array
					for i in `seq 5 5 50`										#loop for result display
					do
					    echo "" >> result_view.txt
					    cat question_bank.txt | head -$i | tail -5 >> result_view.txt
					    echo "" >> result_view.txt

					    if [ ${result[$k]} = "correct" ]
					    then
						echo -e "\e[92mCorrect Answer \e[39m" >> result_view.txt

					    elif [ ${result[$k]} = "wrong" ]
					    then
						echo -e "\e[91mWrong Answer \e[39m" >> result_view.txt
						echo -e "\e[96mCorrect Answer is :  ${correct_ans[$k]} \e[39m" >> result_view.txt		#displaying correct answer if wrong

					    elif [ ${result[$k]} = "timeout" ]
					    then
						echo -e "\e[93mTimeout \e[39m" >> result_view.txt
					    fi
					    k=$(($k + 1))
					done

					echo "" >> result_view.txt
					echo "------------------------------------------------------------------" >> result_view.txt
					echo -e "\e[33mTotal Correct answers :  $count \e[39m" >> result_view.txt				#total correct answers
					echo "------------------------------------------------------------------" >> result_view.txt
					echo "" >> result_view.txt
					cat result_view.txt | more								#displaying the result
					rm user_answer.txt									#removing user_answer.txt
					rm result.txt										#removing result.txt
					rm result_view.txt									#removing result_view.txt
					terminate=0										#to terminate after giving the test
					flag1=0
					flag3=0
					;;
				    2)
					exit											#exit
					;;
				    *)												#default statement
					echo ""
					echo "Please enter correct option !!"
					echo ""
					flag1=0
					flag3=1
					;;

				    esac
				done

			    elif [ $flag2 -eq 1 ]
			    then
				echo ""
				echo "Password not matched, please try again !!"
				echo ""
			    fi
			done	
		    fi


		done
		;;
	    3)															#exit
		exit
		;;
	    *)															#default statement
		echo ""
		echo "Please enter correct option !!"
		echo ""

	    esac

	done
