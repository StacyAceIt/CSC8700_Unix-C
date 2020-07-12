#!/bin/bash

#  palindrometer.sh
#  
#
#  Created by Stacy Zhang on 7/12/20.
#
upperlimit=1000000

testPalindrome(){
     testInput=$1
     reversedNum=`echo $testInput|rev`
     #echo "reversed $reversedNum"
     if [ $testInput -eq $reversedNum ]
      then retval=0
     else
        retval=1
     fi
 return "$retval"
}

findPalindrome(){
 input=$1
 #echo "find palindrome $input "
  while [ $input -lt $upperlimit ]
  do
    testPalindrome $input
    retval=$?
    if [[ "$retval" == 0 ]]
        then echo "$input is palindrome"
        break
#    else
#        echo "$input is not palindrome"

    fi
    input=`echo "$input+1"|bc`
    #input=`echo $input + 1`
  done

}

for i in $1
do
  
  #echo "input $i"
  if [ $i -gt 0 ] && [ $i -lt $upperlimit ]
    then findPalindrome $i
  else
    echo "please enter a six digit number"
  fi
    
done


