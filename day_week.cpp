/*
    Day week date inquiry Progrma
    As a submission to https://code.golf/day-of-week#c

    Created by: amd

*/

// ---------------------------------
// Preprocessor Declaration

#define STR_MAX 100

#include <stdio.h>
#include <time.h>
#include <string.h>

// ---------------------------------
// Progran  Entry Point

int main(int argc, char *argv[])
{
    // ***********************
    // Variable Declaration
    time_t tm01;
    struct tm *ctm01;
    
    int m;
    int d;
    int y;

    int x;

    char str01[STR_MAX];

    // ***********************
    // Actual Procedure


    // checks for argument inputs 
    if(argc>1)
    {

        // procedure if with correct arguments

        // time initialization
        tm01=time( NULL );
        ctm01=localtime(&tm01);

        // processing the inputed argument
        x=1;

        while(x<argc)
        {

            // Extracting arguments into date format

            // Extracting for Year
            snprintf(str01, STR_MAX, "%c%c%c%c", argv[x][0], argv[x][1], argv[x][2], argv[x][3]);
            sscanf(str01, "%i", &y);

            
            // Extracting for Months
            if(argv[x][5]=='0')
            {
                snprintf(str01, STR_MAX, "%c", argv[x][6]);
                sscanf(str01, "%i", &m);
            }else
            {
                snprintf(str01, STR_MAX, "%c%c", argv[x][5], argv[x][6]);
                sscanf(str01, "%i", &m);
            };


            // Extracting for day of the month

            if(argv[x][8] == '0')
            {
                snprintf(str01, STR_MAX, "%c", argv[x][9]);
                sscanf(str01, "%i", &d);

            }else
            {
                snprintf(str01, STR_MAX, "%c%c", argv[x][8], argv[x][9]);
                sscanf(str01, "%i", &d);
            };
            
            // Inserting for proper calendar time
            ctm01->tm_year=(y-1900);
            ctm01->tm_mon=(m-1);
            ctm01->tm_mday=d;

            // Day of the week inquiry
            tm01=mktime(ctm01);
            ctm01=localtime(&tm01);

            // Requesting and printing the week name
            strftime(str01, STR_MAX, "%A", ctm01);
            printf("%s\n", str01);

            x++;
            
        };

    }else
    {
        // If the situation is No Args.
        printf("ERROR: No Argument. ARG must be <YYYY-MM-DD>.\n\n");
    };

    return 0;

};
