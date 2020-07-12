#!/bin/bash

#  mailmerge.sh
#  
#
#  Created by Stacy Zhang on 7/11/20.
#

primary=$1
secondary=$2

numOfLines=$(awk 'END {print NR}' secondary)


for ((i=1; i<=$numOfLines;++i))
do

    first=$(awk -F':' -v var="$i" 'NR==var {print $1}' secondary)
    #echo $first
    second=$(awk -F':' -v var="$i" 'NR==var {print $2}' secondary)
    #echo $second
    third=$(awk -F':' -v var="$i" 'NR==var {print $3}' secondary)
    #echo $third
    fourth=$(awk -F':' -v var="$i" 'NR==var {print $4}' secondary)
    #echo $fourth
    echo ""
    echo ""
    cat primary|sed "s|#1|$first|g;s|#2|$second|g;s|#3|$third|g;s|#4|$fourth|g"
    echo ""
    echo ""
    
done



