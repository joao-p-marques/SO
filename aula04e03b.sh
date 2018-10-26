#!/bin/bash

function select_sort()
{
	unsorted=$1

	min=${unsorted[0]}
	n=0
	for (( i=0; i<${#unsorted[@]}; i++ ))
	do
		if  (( ${unsorted[i]} < $min )) && (( ${unsorted[i]} != 0 )) 
		then
			sorted[$n]=${unsorted[i]}
			((n++))
			min=${unsorted[i]}
			unsorted[i]=0
		fi
	done

	echo sorted ${sorted[@]}

	return 0
}

n=0
while IFS='' read -r line || [[ -n "$line" ]]; do
   	if [[ $line =~ ^[0-9]+$ ]]
	then
		array[n]=$line
		((n++))
	fi
done < "$1"

for (( i=0; i<${#array[@]}; i++ ))
do
	echo ${array[i]}
done

select_sort ${array[@]}
sorted_array=$?

for (( i=0; i<${#sorted_array[@]}; i++ ))
do
	echo ${sorted_array[i]}
done

