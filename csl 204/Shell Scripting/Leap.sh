#!/bin/bash
echo "enter year:"
read yr
if ((yr%4==0 && yr%100!=0 || yr%400==0));then
   echo "$yr is leap"
else
echo "$yr not leap"
fi
