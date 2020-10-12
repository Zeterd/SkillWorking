#!/bin/bash

#PRINT NEW LINE
echo "Hello There"

#WRITING TO FILE
echo "Into The File" > file.txt

#APPEND TO FILE
echo "Appended to the file" >> file.txt

#IF AND ELSE
count=101
flag=1

if [ $count -eq 10 ] && [ $flag -eq 1 ]
then
	echo "The codition is true"
	flag=0

elif [ $count -le 10 ]
then
	echo "some numeber"
else
	echo "What is life?"
fi

#LOOPS

number=1

#Also we can use until
while [ $number -lt 10 ]
do
	echo "$number"
	number=$((number+1))
done

echo "%%%%%%%%%%%%%%%"

#		 {start..ending..increment}
for i in {0..10..2}
do
	echo "$i"
done

echo "%%%%%%%%%%%%%%%"

for ((i=0;i<=10; i++))
do
	if [ $i -gt 5 ]
	then
		break
	fi
	echo "$i"
done

#INPUT SCRIPT

echo $1 #Prints the first argument

args=("$@")
echo ${args[0]} ${args[1]}
echo $@ #print all arguments
echo $# #how many arguments


#while read line
#do
#	echo "$line"
#done < "${1:-/dev/stdin}"


#COMANDS

ls +al 1>output.txt 2> err.txt
ls -al > file.txt

#EXPORT

MESSAGE="Hello Every One!"
export MESSAGE
./secondScript.sh

#
