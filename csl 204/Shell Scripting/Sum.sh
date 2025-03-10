#!/bin/bash
echo "enter number of terms:"
read n
sum=0
for((i=0;i<n;i++))
    do
      echo "enter a number at $i"
      read num
      sum=$((sum+num))
    done
echo"the sum of  $n numbers is : $sum "

