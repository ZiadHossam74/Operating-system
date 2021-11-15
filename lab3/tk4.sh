#!/bin/bash
echo "Enter a number:"
read n
echo "Enter a power:"
read p
if [ $p -gt 0 ]
then
r=$n
for ((i=1;i<$p;i++))
do
r=$((r*n))
done
echo "Result=$r"
else
echo "The power couldnt be negative"
fi
