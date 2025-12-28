#!/usr/bin/env bash
 
./$1 < $2 > outWrong
H1=`md5sum outWrong`
H2=`md5sum $3`
if !(cmp -s "out" "$3")
then
	echo "Error found!"
	echo "Input:"
	cat $2
	echo "Wrong Output:"
	cat outWrong
	echo "True Output:"
	cat $3
	exit
fi
echo Passed pretests

