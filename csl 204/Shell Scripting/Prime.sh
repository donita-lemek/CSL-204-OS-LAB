#!/bin/bash
echo "enter a numbers with spaces"
read -a numbers
echo "put numbers in list"
for num in "${numbers[@]}"
do
  if ((num<=1)); then
     continue
  fi
  is_prime=1
  for ((i=2;i*i<=num;i++))
  do 
    if ((num%i==0)); then
       is_prime=0
       break
    fi
  done
  if ((is_prime==1)); then
     echo -n "$num"
  fi
done
