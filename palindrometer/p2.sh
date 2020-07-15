#!/bin/bash

#  p2.sh
#  
#
#  Created by Stacy Zhang on 7/13/20.
#

findPalindrome(){
    value=$1
    
    str1=$(echo $value|awk '{print substr($0,1,3)}')
    str2=$(echo $value|awk '{print substr($0,4,6)}')

    
    revStr1=`echo $str1|rev`
    echo "revStr1 $revStr1"
    
    if [[ $revStr1 -lt $str2 ]]
    then
        num1=`expr $str1 + 1`
        str1=$(printf "%03d" $num1)
        echo "str1 after increment $str1"
        
    fi

    part1=$str1
    part2=`echo $part1|rev`
    echo "part2 $part2"
    palindrome="${part1}${part2}"
    echo "palindrome $palindrome"
    
    milesLeft=`expr $palindrome - $value`
    echo "miles left $milesLeft"

}


input=$1

#test if input is a six digit number

if [[ $input =~ ^[0-9]{6}$ ]]
then
    findPalindrome $input
else
    echo "invalid input. Please enter a six-digit number"

fi
