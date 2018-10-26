#!/bin/bash
# This script will test if you are on a leap year or not.

if (( $# == 1 ))
then
	year = $1
else
	year = $(date +%Y)
	echo "$year"
fi

if (( $(($year % 400)) == 0 ))
then
	echo "This is a leap year. Feb has 29 days."
elif (( $(($year % 4)) == 0 ))
then
	if ( $(($year %100 != 0 ))
	then
		echo "This is a leap year. Feb has 29 days."
	else
		echo "This is not a leap year. Feb has 28 days."
	fi
else
	echo "This is not a leap year. Feb has 28 days."
fi

