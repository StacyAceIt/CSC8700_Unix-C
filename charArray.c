//
//  charArray.c
//  
//
//  Created by Tianyu Zhang on 7/7/20.
//

#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool checkString(char* myArray,int index){
    
    char currentChar = myArray[index];
    char previousChar = myArray[index-1];
    char extraChar = '#';
    
    if((currentChar == previousChar)&&(currentChar == extraChar)){
        printf("\n need to squeeze extraChar \n");
        
        return true;
    }
    
    if (myArray[index-1]=='\0'){
        printf("\n previous character is null \n");
    }
   // printf("\n previous character: %c \n", previousChar);
    
    printf("\n current character: %c\n ", currentChar);
    
    return false;
    
 
}

int main(){
    
    
    char myArray[1024] = "###Hello##world##";
    
    for(int i = 0; i < strlen(myArray); i++){
        if(checkString(myArray,i)){
            printf("\n main: need to sqeeze \n");
        }
        if(!checkString(myArray,i)){
            printf("\n main: no need to sqeeze \n");
        }
        
    }
    
    return 0;
}
