//
//  twodice.c
//  
//
//  Created by Tianyu Zhang on 7/5/20.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void printStar(int number){
    for(int m = 0; m < number; m++){
        printf("*");
    }
}

int main(){
    int count = 1000;
    int sumArray[13];
    
    for (int j = 0; j < 13; j++){
        sumArray[j] = 0;

    }
    
    for (int i = 0; i < count; i++){
        int d1 = rand()%6+1;
        int d2 = rand()%6+1;
        int sum = d1+d2;
        sumArray[sum] = sumArray[sum] + 1;
    }
    
    printf("\n sum frequency \n");
    for(int s = 2; s <= 12; s++){
        printf("\n %d %d  " ,s,sumArray[s]);
        printStar(sumArray[s]);
        printf("\n");
               
    }
    
    
    return 0;
}
