#!/bin/bash
# This script checks the existance of a file

echo "Checking..."

if (( $# != 1 ))
then
	echo "Invalid number of arguments"
	echo "Usage: $0 <file>"
	exit 1
fi

if [[ -f $1 ]]
then
	echo "File $1 exists"

	if [[ -r $1 ]]
	then
		echo "Is readable"
	fi

	if [[ -w $1 ]]
	then
		echo "Is writable"
	fi

	if [[ -x $1 ]]
	then
		echo "Is executable"
	fi

	if [[ -O $1 ]]
	then
		echo "Is owned by effective user ID"
	fi
else
	echo "Doesn't exist"
fi

echo "...done."
