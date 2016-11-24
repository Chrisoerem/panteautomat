//
//  main.c
//  panteoppgave
//
//  Created by Christer Sørem on 14.11.2016.
//  Copyright © 2016 Christer Sørem. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "ncurses.h"

int FlaskeRegistrering (int);
void start (void);
void Utskrift();

int flasketabell[5];

int main()
{
    int svar;
    start();
    
    while (1)
    {
        scanf(" %d",&svar);
        if (svar==0)
        {
            Utskrift();
            return 0;
        }
        else
        {
            FlaskeRegistrering(svar);
            printf ("Flaske lagt til av type %d\n",svar);
        }
    }
}

int FlaskeRegistrering( int FlaskeType)
{
    return flasketabell[FlaskeType-1]=flasketabell[FlaskeType-1]+1;
    
}


void start ()
{
    char start[7][36] =
    {
        "Hvilken type flaske skal pantes?\n",
        "1. Type 1: 1/3 liter",
        "2. Type 2: 1/2 liter",
        "3. Type 3: 1 liter",
        "4. Type 4: 1 1/2 liter",
        "5. Type 5: Ukurante flasker",
        "Trykk 0 når du er ferdig"
    };
    
    int line;
    for (line = 0; line < 7; line++) {
        printf ("%s\n", start[line]); }
}

void Utskrift()

{
    int x=0,y=0,z=0, i, j, k;
    
    for(i=0;i<=4;i++)
        x=x+flasketabell[i];
    for(j=0;j<=1;j++)
        y=y+flasketabell[j];
    for(k=2;k<=3;k++)
        z=z+(flasketabell[k]*2);
    clear();
    printf("Antall flasker av type 1: %d gir kr %d\n",flasketabell[0], flasketabell[0]);
    printf("Antall flasker av type 2: %d gir kr %d\n",flasketabell[1], flasketabell[1]);
    printf("Antall flasker av type 3: %d gir kr %d\n",flasketabell[2], flasketabell[2]*2);
    printf("Antall flasker av type 4: %d gir kr %d\n",flasketabell[3], flasketabell[3]*2);
    printf("Antall flasker av type 5: %d\n",flasketabell[4]);
    printf("-------------------------------------------\n");
    printf("TOTALT %d flasker gir kr %d\n",x,z+y);
}



