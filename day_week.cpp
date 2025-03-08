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

            snprintf(str01, STR_MAX, "%c%c", argv[x][6], argv[x][7]);
            sscanf(str01, "%i", &m);
            
            snprintf(str01, STR_MAX, "%c%c", argv[x][9], argv[x][10]);
            sscanf(str01, "%i", &d);

            printf("Date: %i - %i - %i\n", m, d, y);



            x++;

        };




    }


    return 0;


};
