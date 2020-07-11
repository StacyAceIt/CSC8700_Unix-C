//
//  negPointer.c
//  
//
//  Created by Tianyu Zhang on 7/7/20.
//

#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//testing what happens in if-statement if the index of array is a negative number


int main(){
    
    char arr1[] = "my array";
    
    printf("\n print array: %c \n",arr1[1]);
    
    if(strcmp('y','y')==0){
        printf("\n true \n");
    }else{
        printf("\n false \n");
    }
    
    return 0;
}
