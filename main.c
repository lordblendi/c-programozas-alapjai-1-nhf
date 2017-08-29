#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include <time.h>

int main()
{
    char meddig[]="igen";
    int meret=200, megtalalt=0, lepes=0,bekeres=0;
    char* valami;
    char a[100];
    FILE* fp;

        printf("Udvozollek az altalam irt memory jatekban!");
        printf("\nValassz jatekmodot:");
        printf("\n1. Jatek");
        printf("\n2. Rekordok megtekintese, aztan jatek");
        printf("\n3. Rekordok megtekintese es kilepes");
        printf("\n4. Kilepes\n");
        scanf("%d",&bekeres);

        if((bekeres==3)||(bekeres==2))
        {
          fp = fopen("records.txt", "r");
          if (fp==NULL)
          {
              printf("\nSikertelen file-nyitasi kiserlet!\n");
              fclose(fp);
          }
          else
          {
              printf("\nAz eddigi rekordok:\n");
              while(!feof(fp))
              {
                  fgets(a,meret,fp);
                  printf("%s",a);
              }
              fclose(fp);
          }

        }

        if((bekeres==1)||(bekeres==2))
        {
            while ((meddig[0]!='n')&&(meddig[1]!='e')&&(meddig[2]!='m'))
            {
                megtalalt=0;
                lepes=0;
                meret=0;
                printf("\n\nHanyas palyan szeretnel jatszani? (2-10, csak paros szamok)");
                scanf("%s",a);
                while(lepes==0)
                {
                    meret=is_digitstr(a);
                    if(meret!=0)
                    {
                        if(((meret%2)!=0)||(meret>10)||(meret<2))
                        {
                            printf("A szam nem paros, vagy nem esik 2 es 10 koze, ezert adj be egy masik szamot!");
                            scanf("%s",a);
                        }
                        else
                        {
                            lepes=1;
                        }
                    }
                    else
                    {
                        printf("Nem szamot adtal meg. Adj meg egy 2 es 10 koze eso paros szamot!");
                        scanf("%s",a);
                    }
                }
                lepes=0;
                valami=(char*)calloc(meret*meret,sizeof(char));

                srand(time(NULL));

                feltoltes(valami, meret);

                while(megtalalt<(meret*meret/2))
                {
                    kiiratas(valami,meret);
                    if(vizsgalas(valami, meret)==1)
                    {
                        megtalalt++;
                    }
                    lepes++;
                }
                printf("\nA jatekot %d lepes alatt oldottad meg.",lepes);
                free(valami);

                printf("\nKerlek ird be a nevedet ekezetek nelkul!");
                gets(a);
                gets(a);
                fp=fopen("records.txt", "a");
                fprintf(fp, "\nJatekos: %s Palyameret: %d * %d Lepesszam: %d",a, meret, meret, lepes);
                fclose(fp);
                printf("Akarsz meg jatszani?");
                scanf("%s",meddig);
            }
        }
    return 0;
}
