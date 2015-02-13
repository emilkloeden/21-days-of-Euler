#!/usr/bin/env bash
clear
i=1
max=1000
answer=0
while [ $i -lt $max ]
do
    if [ $(( i % 3 )) == "0" ] || [ $(( i % 5 )) == "0" ]
        then
            answer=$((answer+i))
    fi
    i=$((i+1))
done
echo $answer