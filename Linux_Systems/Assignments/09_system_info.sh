#! /bin/bash


<<documentation


Name: Harsharaj Nath
Date of Submission: 26-04-22
Description: Write a script to print system information using commands


Sample execution: -

./system_info.sh
1. Currently logged users
2. Your shell directory
3. Home directory
4. OS name & version
5. Current working directory
6. Number of users logged in
7. Show all available shells in your system
8. Hard disk information
9. CPU information.
10. Memory Informations
11. File system information.
12. Currently running process.
Enter the choice : 2
Your shell directory is /bin/bash
Do you want to continue (y/n) ? y
1. Currently logged users
2. Your shell directory
3. Home directory
4. OS name & version
5. Current working directory
6. Number of users logged in
7. Show all available shells in your system
8. Hard disk information
9. CPU information.
10. Memory Informations
11. File system information.
12. Currently running process.
Enter the choice : 13
Error : Invalid option, please enter valid option
Do you want to continue(y/n) ? n


documentation


#########################################_Script_begins_from_here_#########################################


option='y'  				#storing default option as 'y' in variable option

while [ $option = 'y' -o $option = 'Y' ]	#while loop to loop depending upon the option
do
    echo "1. Currently logged users"
    echo "2. Your shell directory"
    echo "3. Home directory"
    echo "4. OS name & version"
    echo "5. Current working directory"
    echo "6. Number of users logged in"
    echo "7. Show all available shells in your system"
    echo "8. Hard disk information"
    echo "9. CPU information."
    echo "10. Memory Informations"
    echo "11. File system information."
    echo "12. Currently running process."
    echo ""
    read -p "Enter the choice : " choice		#taking choice from the user
    echo ""
    case $choice in					#case statements for different choices
	1)
	    echo "Currently logged users are:"
	    echo $USER					#currently logged users
	    ;;
    	2)
    	    echo "Your shell directory is:"
	    echo $SHELL					#shell directory
    	    ;;
    	3)
    	    echo "Home directory is:"
	    echo $HOME					#home directory
    	    ;;
    	4)
    	    echo "OS name and version:"
	    uname -a					#os name and version
    	    ;;
    	5)
    	    echo "Current working directory is:"
	    pwd						#current working directory
    	    ;;
    	6)
    	    echo "Number of users logged in:"
	    who -q					#number od users logged in
    	    ;;
    	7)
    	    echo "All available shells in your system are:"
	    cat /etc/shells					#all available shells in the system
    	    ;;
    	8)
    	    echo "Hard disk information:"
	    lshw					#hard disk information
    	    ;;
    	9)
    	    echo "CPU information:"
	    lscpu					#cpu information
    	    ;;
    	10)
    	    echo "Memory information:"
	    cat /proc/meminfo				#memory information
    	    ;;
    	11)
    	    echo "File system information:"
	    df						#file system information
    	    ;;
    	12)
    	    echo "Currently running processes:"
	    ps						#currently running processes
    	    ;;
    	*)
    	    echo "Error : Invalid option, please enter valid option"		#default statement
    esac
echo ""
read -p "Do you want to continue(y/n) ? " option			#taking option from user whether to continue
done
