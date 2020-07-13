//
//  mday.c
//  
//
//  Created by Stacy Zhang on 7/12/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *getMonth(int monthOfYear){
    static char* monthList[]={"January","Febuary","March","April","May","June","July","August","September","October","November","December"};

    return monthList[monthOfYear];
}



void computeDate(int day,bool leapYear){
    static const char dateList[2][12]=
    {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
     {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    int date = 0;
    char* month;
    
    int rowVal = leapYear ? 1 : 0 ;
    for (int i = 0; i < 13; i++){
        if(day > dateList[rowVal][i]){
            day = day - dateList[rowVal][i];
        }else{
            date = day;
            month = getMonth(i);
            break;
        }
        
    }
    
    printf("\n %d  %s \n",date,month);
    
}

int main(int argc, char *argv[]){
    
    int day = atoi(argv[1]);
    int year = atoi(argv[2]);
    bool leapYear = (year % 4 == 0) ? true : false;
    //printf(leapYear? "true":"false");
  
    //non leap year cannot have more than 365 days
    if((!leapYear) && (day > 365)){

        printf("\n non leap year cannot have more than 365 days! Please enter again \n");

    }else if((leapYear) && (day > 366)){
        printf("\n leap year cannot have more than 366 days! Please enter again \n");
    }else{
        computeDate(day,leapYear);
    }

    
    return 0;
}
