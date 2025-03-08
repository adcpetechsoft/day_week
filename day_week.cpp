#define STR_MAX 100

#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[])
{
    time_t tm01;
    struct tm *ctm01;
    
    int m;
    int d;
    int y;

    int x;

    char str01[STR_MAX];

    if(argc>1)
    {
        tm01=time( NULL );
        ctm01=localtime(&tm01);

        x=1;

        while(x<argc)
        {

            snprintf(str01, STR_MAX, "%c%c%c%c", argv[x][0], argv[x][1], argv[x][2], argv[x][3]);
            sscanf(str01, "%i", &y);

            snprintf(str01, STR_MAX, "%c%c", argv[x][5], argv[x][6]);
            sscanf(str01, "%i", &m);
            
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
