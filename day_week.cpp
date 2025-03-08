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
    if(argc>1)
    {
        tm01=time( NULL );
        ctm01=localtime(&tm01);

        x=1;

        while(x<argc)
        {

            snprintf(str01, STR_MAX, "%c%c%c%c", argv[x][0], argv[x][1], argv[x][2], argv[x][3]);
            sscanf(str01, "%i", &y);

            if(argv[x][5]=='0')
            {
                snprintf(str01, STR_MAX, "%c", argv[x][6]);
                sscanf(str01, "%i", &m);
            }else
            {
                snprintf(str01, STR_MAX, "%c%c", argv[x][5], argv[x][6]);
                sscanf(str01, "%i", &m);
            };

            if(argv[x][8] == '0')
            {
                snprintf(str01, STR_MAX, "%c", argv[x][9]);
                sscanf(str01, "%i", &d);

            }else
            {
                snprintf(str01, STR_MAX, "%c%c", argv[x][8], argv[x][9]);
                sscanf(str01, "%i", &d);
            }
            
            
            snprintf(str01, STR_MAX, "%c%c", argv[x][8], argv[x][9]);
            sscanf(str01, "%i%i", &d, &d);

            ctm01->tm_year=(y-1900);
            ctm01->tm_mon=(m-1);
            ctm01->tm_mday=d;

            tm01=mktime(ctm01);
            ctm01=localtime(&tm01);

            strftime(str01, STR_MAX, "%A", ctm01);

            printf("%s\n", str01);

            x++;

        };

    };

    return 0;

};
