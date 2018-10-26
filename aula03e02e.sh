#!/bin/bash

if (( $1 > 5 )) && (( $1 < 10 ))
then
	echo "Número maior que 5 e menor que 10"
else
	echo "Número menor pu igual que 5 ou maior ou igual que 10"
fi
