#!/bin/bash
T=0
c=0
f=0
while [ $f -eq 0 ]
do
echo "Enter a positive integers"
read n
if [ $n -gt 0 ]
then
f=0
T=$((T+n))
c=$((c+1))
elif [ $n -lt 0 ]
then
f=0
echo "Error"
else
f=1
fi
done
AV=$((T/c))
echo "The average=$AV"
