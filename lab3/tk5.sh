#!/bin/bash
echo "Enter a number"
read n
for((i=0;i<=$n;i++))
do
t=$(($n % i))
if [ t -eq 0 ]
then
c++
fi
done
if [ $c -eq 2 ]
then
echo "The number ($n) is a prime number "
else
echo "The number ($n) is not a prime number "
fi
