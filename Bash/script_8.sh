#! /bin/bash

echo "Enter directory name: "
read dir

if [ -d "$dir" ]
then
	echo "$dir directory exists!!"
	echo "Do you want to delete it?"
	read resp

	if [ "$resp" == "y" ]
	then
		rm -rf $dir
		echo "Directory deleted!!"
	else
		echo "Ok thanks for replied :) "
	fi
else
	echo "$dir not exist!!"
	echo "Want to create with the name $dir?"
	read resp

	if [ "$resp" == "y" ]
	then
		mkdir $dir
		echo "Directory created!!"
	else
		echo "Ok thanks for replied :) "
	fi
fi
