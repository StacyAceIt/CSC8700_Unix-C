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

void cflow(char input[]){
    
    int counter = 0;
    for(int i = 0; i < strlen(input); i++){
        if(input[i]>='a' && input[i]<='z'){
            //printf("\n lowercase letter %c \n",input[i]);
            char temp = input[i];
            input[i] = ' ';
            input[i-counter] = temp;
            
        }else if(input[i]>='A' && input[i]<='Z'){
            //printf("\n uppercase letter %c \n",input[i]);
            //input[i-counter] = tolower(input[i]);
            
            char temp = input[i];
            input[i] = ' ';
            input[i-counter] = tolower(temp);
            
            
        }else if(input[i-counter+1]!=' ' && input[i]==' '){
            char temp = input[i];
            input[i] = ' ';
            input[i-counter] = temp;
            
        }
        else{
            //printf("\n non letter %c \n",input[i]);
            input[i] = ' ';
            counter++;
            //printf("\n num of non letters: %d \n",counter);
            
        }
        
    }
    
    
    printf("\n cflow string: %s \n", input);
}

void cfdig(char input[]){
    
    int counter = 0;
    for(int i = 0; i < strlen(input); i++){
        if(!isdigit(input[i]) && (input[i]!=' ')){
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
    
    printf("\n output cfdig string: %s \n", input);
}

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
