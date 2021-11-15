#!/bin/bash
echo "Enter your  gross salary "
read gs
if [ $gs -gt 2000 ]
then
echo "hi1"
s=$((gs-(gs*15/100)))
elif [ $gs -ge 1000 ]
then
echo "hi2"
s=$((gs-(gs*10/100)))
else
echo "el"
fi
echo "Your net salary after tax reduction: $s"


