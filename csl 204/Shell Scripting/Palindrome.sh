echo "enter a number (n):"
read n
temp=$n
r=0
while ((temp>0))
    do
      r=$((r*10+temp%10))
      temp=$((temp/10))
    done
if ((r==n))
   then echo "palindrome"
else
    echo "not palindrome"
fi
