#!/bin/bash

PROBLEM=kon
COUNTER=0
AMOUNT=18

while [ $COUNTER -lt $AMOUNT ]
do
	./p < $PROBLEM$COUNTER.in > out.out
	DIFF=$(diff -w $PROBLEM$COUNTER.out out.out)
	if [ "$DIFF" != "" ]
	then
		echo ANS $COUNTER
	fi
	((COUNTER++))
done

echo ALL $AMOUNT TESTS DONE
