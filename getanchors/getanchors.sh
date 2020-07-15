#!/bin/bash

#  getanchors.sh
#  
#
#  Created by Stacy Zhang on 7/12/20.
#  


grep -o '<a href=[^<]*'|sed 's/<a href="//g;s/>/    /g;s/\"//g'



