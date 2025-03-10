/*
    Day week date inquiry Progrma
    As a submission to https://code.golf/day-of-week#c

    Created by: amd

*/

// ---------------------------------
// Preprocessor Declaration

#define STR_MAX 100

#define P_OK 0
#define P_ERR_VAL -5
#define P_ERR_IO -10

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char str01[STR_MAX];
int str01_pos;

int m;
int d;
int y;


// ---------------------------------
// Function contoi declaration
// use to  convert string to integer

int contoi()
{
    // ***********************
    // Variable Declaration
    int res;
    int i;

    char buff01[STR_MAX];
    char *buff01_tail;

    // ***********************
    // Actual Function

    // Temporary string initialization
    buff01[0]='\0';
    buff01_tail=NULL;
    
    // Scanning, slicing and placing input to temp string
    i=0;
    do
    {
        buff01[i]=str01[str01_pos];
        i++;
        str01_pos++;
    }while ( str01[str01_pos] != '\0' && str01[str01_pos] != '-' && isdigit(str01[str01_pos]) );

    buff01[i]='\0';

    // Actual str to integer conversion
    res=strtol(buff01, &buff01_tail, 0);

    // incremant global string position
    str01_pos++;

    // return the converted answer
    return res;
};

// ---------------------------------
// Function cal declaration
// use to format integers into calendar variables
int cal()
{
    // ***********************
    // Variable Declaration
    int res;


    // ***********************
    // Actual Function

    // initial global string position
    str01_pos=0;

    // Pre calendar values
    m=0;
    d=0;
    y=0;

    // call to process the calender variables
    y=contoi();
    m=contoi();
    d=contoi();

    // Validating Calendar variables
    if(m>=1 && m<=12 && d>=1 && d<=31)
    {
        res=P_OK;
    }else
    {
        res=P_ERR_VAL;
    };

    // return the result
    return res;

};

// ---------------------------------
// Progran  Entry Point

int main(int argc, char *argv[])
{
    // ***********************
    // Variable Declaration
    time_t tm01;
    struct tm *ctm01;

    int x;
    

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
            snprintf(str01, STR_MAX, "%s", argv[x]);

            if( (cal() ) == P_OK )
            {
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

            }else
            {
                printf("ERROR: y:%i m:%i d:%i s:%s\n", y, m, d, str01);
            };

            x++;
        };

    }else
    {
        // If the situation is No Args.
        printf("ERROR: No Argument. ARG must be <YYYY-MM-DD>.\n\n");
    };

    return 0;

};
