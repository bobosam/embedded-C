#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
   int day, year, month, weekday;
   char dtm[100];
               
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%d.%m.%Y", tm_info);
    
   strcpy( dtm, buffer);
   sscanf( dtm, "%d.%d.%d\n", &day, &month, &year );
   int dayNow = day;
   int monthNow = month;
   int yearNow = year;
   
   char birthday[11];
   printf("Please enter birthday in format DD.MM.YYYY: ");
   scanf("%10s", birthday);
   
   strcpy( dtm, birthday);
   sscanf( dtm, "%d.%d.%d\n", &day, &month, &year );
   int dayBirthday = day;
   int monthBirthday = month;
   int yearBirthday = year;
   
   int ageNow = yearNow - yearBirthday;
   if ((monthNow - monthBirthday) < 0) 
   {
       ageNow--;
    }
   
   if (monthBirthday == monthNow && (dayNow - dayBirthday) < 0)
   {
       ageNow--;
    }

   int afterTenYears = ageNow +10;
   
   printf("Now: %d\n", ageNow);
   printf("After 10 years: %d\n",afterTenYears );
    
   return(0);
}

