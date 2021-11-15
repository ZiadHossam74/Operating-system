#!/bin/bash
nos=""
echo "Enter the number of seconds"
read nos
h=$((nos/60/60))
m=$((((nos-$((h*60*60))))/60))
s=$((nos-$((h*60*60))-$((m*60))))
echo "The time is  $h : $m : $s"
