#!/usr/bin/env bash
#stress.sh solutionWrong solutionSlow generator numTests 
for ((testNum=0;testNum<$4;testNum++))
do
    ./$3 > input
    ./$2 < input > outSlow
    ./$1 < input > outWrong
    if !(diff -qBb outWrong outSlow > /dev/null);
    then
        echo "Error found!"
        echo -e "\nInput:"
        cat input
        echo -e "\nWrong Output:"
        cat outWrong
        echo -e "\nCorrect Output:"
        cat outSlow
		echo -e "\n"
        exit
    fi
	#echo -e "test $testNum passed" 
done
echo Passed $4 tests