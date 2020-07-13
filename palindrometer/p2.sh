#!/bin/bash

#  p2.sh
#  
#
#  Created by Stacy Zhang on 7/13/20.
#

findPalindrome(){
    value=$1
    #echo $value
    
    str1=$(echo $value|awk '{print substr($0,1,3)}')
    str2=$(echo $value|awk '{print substr($0,4,6)}')
    
    # 0{2} removes a maximum of 2 leading zeros # it won't word without /g
    num1=$(echo $str1|sed 's/^0\{2\}//g')
    echo "num1 $num1"
#    num2=$(echo $str2|sed 's/^0*//')
    
    revNum1=`echo $str1|rev`
    echo "revNum1 $revNum1"
    
    if [[ $revNum1 -lt $str2 ]]
    then
        #echo "before converting str1 $str1"
        num1=`expr $num1 + 1`
        #echo "after converting str1 $str1"
#    else
#        num1=$(echo $str1|sed 's/^0*//')
    fi
    
    echo "(incremented) num1 $num1"
    
    #if we don't strip leading zeros of str1, this line will treat num1 as octal
    #and output its corresponding decimal
    part1=$(printf "%03d\n" $num1)
    echo "part1 $part1"
    
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
