#!/bin/bash -i
# Conditional block if

echo ---------------
ll
echo ---------------

if $1
then
	echo "Verdadeiro"
else
	echo "Falso"
fi

