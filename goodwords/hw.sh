#!/bin/bash

#  hw.sh
#  
#
#  Created by Stacy Zhang on 7/12/20.
#  

#!/bin/bash



fourLetterWords=$(awk '{
if(length($0)==5)
    {
    var1=substr($0,1,2);
    var2=substr($0,4,2);
    newVar=var1 var2;
    print newVar;
    
    
    }
}' hello_world)

#echo "awk $fourLetterWords"
echo ""

#cat hello_world|grep -i '^.....$'|sed 's/.//3'

for i in  $fourLetterWords
do
 if grep $i hello_world
  then echo "$i is in dictionary"
# else
#  echo "$i is not in dictionary"
 fi

done

fourLetterWords3=$(cat hello_world|grep -i '^.....$'|awk '{print substr($0,1,2) substr($0,4,2)}')
echo " 3 $fourLetterWords3"


