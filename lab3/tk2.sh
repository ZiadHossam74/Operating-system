#!/bin/bash
echo "Enter a temperature in degrees Celsius :"
celsius=""
read celsius
Fahrenheit=$(((celsius*(9/5))+32))
echo $Fahrenheit
