#!/bin/bash

#  flow.sh
#  
#
#  Created by Stacy Zhang on 7/4/20.
#  
#!/bin/bash


flow(){
    fileName=$1
    echo "flow: translate all letters to lowercase, non letters to a space, squeeze consecutive spaces"
    while read line
    do
        echo "$line"|tr '[A-Z]' '[a-z]'|sed 's/[^A-Za-z]/ /g'|tr -s ' ' ' '
    
    done<$fileName

}

fup(){
    fileName=$1
    echo "fup: remove uppercase letters, squeeze consecutive spaces"
    while read line
    do
        echo "$line"|tr -d '[A-Z]'|tr -s ' ' ' '
    
    done<$fileName

}

fdig(){
    fileName=$1
    echo "fdig: remove digits, squeeze consecutive spaces"
    while read line
    do
        echo "$line"|tr -d '[0-9]'|tr -s ' ' ' '
    
    done<$fileName

}

chooseScript(){
    myScript=$1
    fileName=$2
    echo "chooseScript: $myScript"
    
    #need to have a whitespace after [ and before ]
    if [ $myScript = 'flow' ];
    then
        flow $fileName
    elif [ $myScript = 'fup' ];
    then
        fup $fileName
    else
        fdig $fileName
    fi
}

rm fup
rm fdig
ln flow fup
ln flow fdig

for fileName in $*
do
    myScript=`basename $0`
    fileName=$fileName
    echo "main myScript $myScript"
    
    chooseScript $myScript $fileName
    

done
