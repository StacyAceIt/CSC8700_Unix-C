#!/bin/bash

#  swap
#  
#
#  Created by Stacy Zhang on 7/4/20.
#

successorLetterToAscii(){
    letter=$1
    asciiNumber=$(printf "%d" "'$letter")
    nextAscii=`echo "$asciiNumber+1"|bc`
    #echo "next ascii: $nextAscii"
    nextLetter=$(printf "\x$(printf %x $nextAscii)")
    echo "next letter: $nextLetter"
    #echo "letterToAscii letter $i: ascii $asciiNumber"

}

getSuccessor(){
    letter=$1
    if [ $letter = 'z' ];
    then
        echo 'a'
    elif [ $letter = 'Z' ];
    then
        echo 'A'
    else
        successorLetterToAscii $letter
    fi
}

swap(){
    word=$1
    echo "transferring to succeeding letters"
    
    for i in $(seq 1 ${#word})
    do
        echo "$i: ${word:i-1:1}"
        letter=${word:i-1:1}
        echo "transfer to "
        getSuccessor $letter
    done

}

predecessorLetterToAscii(){
    letter=$1
    asciiNumber=$(printf "%d" "'$letter")
    lastAscii=`echo "$asciiNumber-1"|bc`
    #echo "last ascii: $lastAscii"
    lastLetter=$(printf "\x$(printf %x $lastAscii)")
    echo "last letter: $lastLetter"
    #echo "letterToAscii letter $i: ascii $asciiNumber"

}

getPredecessor(){
    letter=$1
    if [ $letter = 'a' ];
    then
        echo 'z'
    elif [ $letter = 'A' ];
    then
        echo 'Z'
    else
        predecessorLetterToAscii $letter
    fi
}

wpaws(){
    word=$1
    echo "transferring to preceding letters"
    
    for i in $(seq 1 ${#word})
    do
        echo "$i: ${word:i-1:1}"
        letter=${word:i-1:1}
        echo "transfer to "
        getPredecessor $letter
    done

}

rm wpaws
ln swap wpaws

myScript=`basename $0`

for word in $*
do

    echo "executing $myScript"
    echo "reversing $word"
    revWord=`echo $word|rev`
    echo "$revWord"
    
    if [ $myScript = "swap" ]
    then
        swap $revWord
    elif [ $myScript = "wpaws" ]
    then
        wpaws $revWord
    else
        echo "cannot process characters"
    fi

done
