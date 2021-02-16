#!/bin/bash

for (( i = 1; i <= 6; i++ ))
do
	echo "running test $i"
	./test$i.py
done

