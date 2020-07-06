#!/bin/bash

#  findword.sh
#  
#
#  Created by Stacy Zhang on 7/4/20.
#  


char=$1
myletters=$2
dict=$3




startWith=`grep "^$char" $dict`

for i in $(seq 1 ${#myletters})
do
    letter=${myletters:i-1:1}
    #echo "$letter"
    #echo "$startWith"|grep $letter
    #echo "$startWith"|grep $letter|wc -w
    startWith=`echo "$startWith"|grep $letter`

    #echo "$startWith"|grep $letter|wc -w

done

echo "$startWith"

