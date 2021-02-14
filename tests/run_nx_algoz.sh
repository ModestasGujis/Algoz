#!/bin/bash

echo 'nx lib:'
time ./nx_shortest_path.py > nx_rez
echo 'our lib <3 :'
time ./algoz_shortest_path.py > algoz_rez

DIFF=$(diff nx_rez algoz_rez) 
if [ "$DIFF" != "" ] 
then
	echo "BLOGI REZULTATAI"
fi