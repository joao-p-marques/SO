#!/bin/bash

function imprime_msg()
{
	echo "1a função em bash"
	return 0
}

function info()
{
	date	
	hostname # ou echo $HOSTNAME
	echo $USER # ou id -un
	return 0
}

