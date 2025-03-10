#!/bin/bash
echo "enter number of terms (n):"
read n
a=0
b=1
for((i=1;i<=n;i++))
   do
     echo -n "$a"
     fn=$((a+b))
     a=$b
     b=$fn
   done
echo
