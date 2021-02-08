#!/bin/bash

for (( i = 1; i <= 3; i++ ))
do
	echo "running test $i"
	./test$i.py
done

