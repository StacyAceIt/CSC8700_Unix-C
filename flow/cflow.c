//
//  cflow.c
//  
//
//  Created by Tianyu Zhang on 7/1/20.
//

#include <libgen.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void cflow(char input[]){
    
    int counter = 0;
    for(int i = 0; i < strlen(input); i++){
        if(input[i]>='a' && input[i]<='z'){
            //printf("\n lowercase letter %c \n",input[i]);
            char temp = input[i];
            input[i] = '#';
            input[i-counter] = temp;
            
        }else if(input[i]>='A' && input[i]<='Z'){
            //printf("\n uppercase letter %c \n",input[i]);
            //input[i-counter] = tolower(input[i]);
            
            char temp = input[i];
            input[i] = '#';
            input[i-counter] = tolower(temp);
            
            
        }else if(input[i-counter-1]!='#' && input[i]=='#'){
            char temp = input[i];
            input[i] = '#';
            input[i-counter] = temp;
            
        }
        else{
            //printf("\n non letter %c \n",input[i]);
            input[i] = '#';
            counter++;
            //printf("\n num of non letters: %d \n",counter);
            
        }
        
    }
    
    
    printf("\n cflow string: %s \n", input);
}

bool prevCharIsExtraChar(char* input, int i, char extraChar){
    
    char previousChar = input[i-1];
    char currentChar = input[i];
    
    if(previousChar != '\0'){
        
        if((previousChar == currentChar) &&(currentChar == extraChar)){
            return true;
        }
        
        
    }
    
    return false;
}

void cfdig(char input[]){
    int numOfKeepers = 0;
    int keeperMoveToThisIndex = numOfKeepers - 1;
    char extraChar = '#';
    
    char output[1024];
    
    for(int i = 0; i < strlen(input); i++){

        if((!isdigit(input[i]))&&(!prevCharIsExtraChar(input,i,extraChar))){
            
            numOfKeepers = numOfKeepers + 1;
            output[keeperMoveToThisIndex] = input[i];
        }
    }
    
}

//void cfdig(char input[]){
//    //remove digits
//
//    int counter = 0;
//    for(int i = 0; i < strlen(input); i++){
//        //remove extra whitespaces
//        if((i-counter)>=1 && input[i-counter-1]=='#' && input[i]=='#'){
//
//            printf("\n i = %d c = %d \n",i,counter);
//            printf("\n rm ws - before substitute: %c \n", input[i]);
//
//            input[i] = '#';
//
//            printf("\n rm ws - after substitute: %c \n", input[i]);
//
//
//        }
//        else if(isdigit(input[i])){
//
//            printf("\n i = %d c = %d \n",i,counter);
//
//            //remove digits
//            printf("\n rm dg - before substitute: %c \n", input[i]);
//
//            input[i] = '#';
//
//            printf("\n rm dg - after substitute: %c \n", input[i]);
//
//        }else{
//
//            printf("\n i = %d c = %d \n",i,counter);
//
//            printf("\n keep - before substitute: %c \n", input[i]);
//
//            char temp = input[i];
//            input[i] = '#';
//            input[i-counter] = temp;
//
//            counter++;
//
//            printf("\n keep - after substitute: %c \n", input[i]);
//        }
//
//    }
//
//    printf("\n output cfdig string: %s \n", input);
//}

void cfup(char input[]){
    
    int counter = 0;
    for(int i = 0; i < strlen(input); i++){
        if(!isupper(input[i]) && (input[i]!=' ')){
            char temp = input[i];
            input[i] = ' ';
            input[i-counter] = temp;
        }else if(input[i-counter+1]!=' ' && input[i]==' '){
            char temp = input[i];
            input[i] = ' ';
            input[i-counter] = temp;
            
        }else{
            input[i] = ' ';
            counter++;
        }
        
    }

    printf("\n output cfup string: %s \n", input);
}


int main(int argc, char* argv[]){
    char input[1024];
    char* mode = basename(argv[0]);
    
    printf("Enter a string: \n");
    fgets(input,1024,stdin);
    printf("\nProcessing string %s \n",input);
    
    if(strcmp(mode,"cflow")==0){
        cflow(input);
    }else if(strcmp(mode,"cfup")==0){
        cfup(input);
    }else if(strcmp(mode,"cfdig")==0){
        cfdig(input);
    }
    
    return 0;
}
