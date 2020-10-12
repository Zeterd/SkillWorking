#! /bin/bash

#ARRAYS

car=('BMW' 'TOYOTA' 'HONDA' 'MERCEDES' 'SEAT')

echo "${car[0]}"
echo "${car[@]}"
echo "${!car[@]}"
echo "${#car[@]}"
unset car[2]
echo "${car[@]}"
echo "${!car[@]}"
car[2]="RENAULT"
echo "${car[@]}"