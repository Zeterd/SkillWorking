#! /bin/bash

#ARITEMETIC OPERATIONS

n1=5
n2=20

echo $(( n1+n2 ))
echo $(( n1*n2 ))
echo $(( n1/n2 ))
echo $(( n1-n2 ))

echo "%%%%%%%%%%%%%%%%%%%"

echo $(expr $n1 + $n2)
echo $(expr $n1 - $n2)
echo $(expr $n1 \* $n2)
echo $(expr $n1 / $n2)
echo $(expr $n1 % $n2)

echo "%%%%%%%%%%%%%%%%%%%"

echo "Enter Hex number:"
read Hex

echo -n "The decimal value of $Hex is: "
echo "obase=10; ibase=16; $Hex" | bc
