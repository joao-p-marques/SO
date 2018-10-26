#!/bin/bash

function compare_int()
{
	if (( $1 > $2 )) 
	then
		return 1
	elif (( $2 > $1 )) 
	then
		return 2
	else
		return 0
	fi
}

read v1
read v2

compare_int $v1 $v2

r=$?
if (( $r == 0 ))
then
	echo "Os dois nº são iguais"
elif (( $r == 1 ))
then
	echo "O maior nº é $v1"
else
	echo "O maior nº é $v2"
fi

