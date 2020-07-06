#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <libgen.h>

void toLower(char s[]) {
    for(int loop=0; loop<strlen(s); loop++) {
        if(s[loop] >=65 && s[loop] <= 90) {
            s[loop] = tolower(s[loop]);
        }        
    }
}

void keeplower(char s[]) {
    int j=0;
    for(int loop=0; loop<strlen(s); loop++) {
        if(islower(s[loop]) && (s[loop] != ' ')) {
            s[j] = s[loop];
            j++;
        } else {
            if((j==0) || (s[j-1] != ' ')) {
                s[j] = ' ';
                j++;
            }            
        }      
    }
    s[j] = '\0';
}

void removenumeric(char s[]) {
    int j=0;
    for(int loop=0; loop<strlen(s); loop++) {
        if(!isdigit(s[loop]) && (s[loop] != ' ')) {
            s[j] = s[loop];
            j++;
        }  
        else {
            if((j!=0) && (s[j-1] != ' ')) {
                s[j] = ' ';
                j++;
            }            
        }
    }
    s[j] = '\0';
}

void removeupper(char s[]) {
    int j=0;
    for(int loop=0; loop<strlen(s); loop++) {
        if(!isupper(s[loop]) && (s[loop] != ' ')) {
            s[j] = s[loop];
            j++;
        }  
        else {
            if((j!=0) && (s[j-1] != ' ')) {
                s[j] = ' ';
                j++;
            }            
        }
    }
    s[j] = '\0';
}

int main(int argc, char* argv[]){
    char* exe_name = basename(argv[0]);
    char str[1024];
    printf("Enter input String for %s: ", exe_name);
    fgets(str, 1024, stdin);
    if(strcmp(exe_name, "cflow") == 0) {
        toLower(str);
        keeplower(str);
    } else if(strcmp(exe_name, "cfup") == 0) {
        removeupper(str);
    } else if(strcmp(exe_name, "cfdig") == 0) {
        removenumeric(str);
    }
    printf("The output is: %s", str);
    return 0;
}