#include<stdio.h>
#include<stdlib.h>
char *month_name(int n)
{
    static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}


static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Invalid number of arguments. \n Usage: mday <days> <year>\n");
        exit(1);
    }
    int year = atoi(argv[2]);
    int days = atoi(argv[1]);
    
    int month;
    int day;

    
    month_day(year, days, &month, &day);
    char* monthStr = month_name(month);
    printf("%s %d\n" , monthStr, day);
    exit(0);
}
