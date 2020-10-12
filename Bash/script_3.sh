#! /bin/bash

#STRINGS

echo "Enter first string"
read str1

echo "Enter second string"
read str2

if [ "$str1" == "$str2"  ]
then
	echo "Strings are the same!"
elif [ "$str1" \< "$str2" ] 
then
	echo "$str1 is smaller than $str2"
elif [ "$str1" \> "$str2" ]
then
	echo "$str2 is smaller than $str1"
else
	echo "Strings are equal length"
fi

##Concat

str=$str1$str2
echo "$str"

##Lower and upper case

echo ${str1^}
echo ${str1^^}



