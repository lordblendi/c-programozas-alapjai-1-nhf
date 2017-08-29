#include <stdio.h>
#include <stdlib.h>

void feltoltes(char* tomb, int meret)
{
    int i=0, karakter=36;

    for(i=0;i<(meret*meret/2);i++)
    {
        int j=0;
        for(j=0;j<2;j++)
        {
            int rnd=rand()%(meret*meret);
            while(tomb[rnd]!=0)
            {
                rnd = (rnd+1)%(meret*meret);
            }
            tomb[rnd]=karakter;
        }
        karakter++;
    }
}
void kiiratas(char* tomb,  int meret)
{
    int i=0, j=0, sor=0;
    //clrscr();
    printf("\n\n\nx  ");

    for(i=0;i<meret;i++)
    {
        printf("%c ",i+97);
    }

    printf("\ny\n  ");
    for(sor=0;sor<meret;sor++)
    {
        printf("\n%d  ", sor);
        for (j=0; j < meret;j++)
        {
            if(tomb[sor*meret+j]==1)
            {
                printf("%c ",tomb[sor*meret+j]);
                //printf("%c ",' ');
            }
            else if(tomb[sor*meret+j]!=0)
            {
                //printf("%c ",tomb[i*meret+j]);
                printf("%c ",'#');
            }
        }
    }

}
int vizsgalas(char* tomb, int meret)
{
    char elso[3], masodik[3];
    int x1=0, x2=0, y1=0, y2=0, i=0, j=0, sor=0, vmi=0;

    printf("\n\nAdja meg az elso elem koordinatait (pl.:a1)");
    scanf("%s",elso);
    while(vmi==0)
    {
        switch (elso[0])
        {
            case 'a':
                x1=0;vmi=1;
            break;
            case 'b':
                x1=1;
                vmi=1;
            break;
            case 'c':
                x1=2;
                vmi=1;
            break;
            case 'd':
                x1=3;
                vmi=1;
            break;
            case 'e':
                x1=4;
                vmi=1;
            break;
            case 'f':
                x1=5;
                vmi=1;
            break;
            case 'g':
                x1=6;
                vmi=1;
            break;
            case 'h':
                x1=7;
                vmi=1;
            break;
            case 'i':
                x1=8;
                vmi=1;
            break;
            case 'j':
                x1=9;
                vmi=1;
            break;
            default:
                printf("Ilyet betut nem adhatsz meg.");
                vmi=0;
        }
        if((elso[1]==NULL)&&(vmi==1))
        {
            printf("Ilyen koordinatat nem adhatsz meg.");
            vmi=0;
        }
        else
        {
            y1=elso[1]-'0';
        }

        if(vmi==1)
        {
            if((y1>=meret)||(x1>=meret))
            {
                printf("Ez az elem nem a palya resze. Adj meg egy masikat!");
                vmi=0;
                printf("Adja meg ujra az elso elem koordinatait (pl.:a1)");
                scanf("%s",elso);
            }
        }

        else
        {
            printf("\nAdja meg ujra az elso elem koordinatait (pl.:a1)");
            scanf("%s",elso);
        }
    }

    if(tomb[y1*meret+x1]==1)
    {
        while(tomb[y1*meret+x1]==1)
        {
            vmi=0;
            printf("Ez a koordinata mar volt! Adj meg egy masikat!");
            scanf("%s",elso);

            while(vmi==0)
            {
                switch (elso[0])
                {
                    case 'a':
                        x1=0;
                        vmi=1;
                    break;
                    case 'b':
                        x1=1;
                        vmi=1;
                    break;
                    case 'c':
                        x1=2;
                        vmi=1;
                    break;
                    case 'd':
                        x1=3;
                        vmi=1;
                    break;
                    case 'e':
                        x1=4;
                        vmi=1;
                    break;
                    case 'f':
                        x1=5;
                        vmi=1;
                    break;
                    case 'g':
                        x1=6;
                        vmi=1;
                    break;
                    case 'h':
                        x1=7;
                        vmi=1;
                    break;
                    case 'i':
                        x1=8;
                        vmi=1;
                    break;
                    case 'j':
                        x1=9;
                        vmi=1;
                    break;
                    default:
                        printf("Ilyet betut nem adhatsz meg. Adj meg egy uj koordinatat!");
                        vmi=0;
                }
                if((elso[1]==NULL)&&(vmi==1))
                {
                    printf("Ilyen koordinatat nem adhatsz meg");
                    vmi=0;
                }
                else
                {
                    y1=elso[1]-'0';
                }

                if(vmi==1)
                {
                    if((y1>=meret)||(x1>=meret))
                    {
                        printf("Ez az elem nem a palya resze. Adj meg egy masikat!");
                        vmi=0;
                        printf("Adja meg ujra az elso elem koordinatait (pl.:a1)");
                        scanf("%s",elso);
                    }
                }

                else
                {
                    printf("\nAdja meg ujra az elso elem koordinatait (pl.:a1)");
                    scanf("%s",elso);
                }
            }

        }
    }

    printf("\nAdja meg a masodik elem koordinatait (pl.:a2)");
    scanf("%s",masodik);

    i=0;
    vmi=0;
    while(vmi==0)
    {
        switch (masodik[0])
        {
            case 'a':
                x2=0;
                vmi=1;
            break;
            case 'b':
                x2=1;
                vmi=1;
            break;
            case 'c':
                x2=2;
                vmi=1;
            break;
            case 'd':
                x2=3;
                vmi=1;
            break;
            case 'e':
                x2=4;
                vmi=1;
            break;
            case 'f':
                x2=5;
                vmi=1;
            break;
            case 'g':
                x2=6;
                vmi=1;
            break;
            case 'h':
                x2=7;
                vmi=1;
            break;
            case 'i':
                x2=8;
                vmi=1;
            break;
            case 'j':
                x2=9;
                vmi=1;
            break;
            default:
                printf("Ilyet betut nem adhatsz meg. Adj meg egy uj koordinatat!");
                vmi=0;
        }
        if((masodik[1]==NULL)&&(vmi==1))
        {
            printf("Ilyen koordinatat nem adhatsz meg");
            vmi=0;
        }
        else
        {
            y2=masodik[1]-'0';
        }

        if(vmi==1)
        {
            if((y2>=meret)||(x2>=meret))
            {
                printf("Ez az elem nem a palya resze. Adj meg egy masikat!");
                vmi=0;
                scanf("%s",masodik);
            }
            else if((x1==x2)&&(y1==y2))
            {
                printf("Ez az elem nem egyezhet meg az elozovel. Adj meg egy masikat!");
                vmi=0;
                scanf("%s",masodik);
            }
        }

        else
        {
            printf("\nAdja meg ujra a masodik elem koordinatait (pl.:a1)");
            scanf("%s",masodik);
        }
    }

    vmi=0;

    while(tomb[y2*meret+x2]==1)
    {
        printf("Ezt az elemet mar egyszer megtalaltad. Adj meg egy masikat!");
        scanf("%s",masodik);
        vmi=0;

        while(vmi==0)
        {
            switch (masodik[0])
            {
                case 'a':
                    x2=0;
                    vmi=1;
                break;
                case 'b':
                    x2=1;
                    vmi=1;
                break;
                case 'c':
                    x2=2;
                    vmi=1;
                break;
                case 'd':
                    x2=3;
                    vmi=1;
                break;
                case 'e':
                    x2=4;
                    vmi=1;
                break;
                case 'f':
                    x2=5;
                    vmi=1;
                break;
                case 'g':
                    x2=6;
                    vmi=1;
                break;
                case 'h':
                    x2=7;
                    vmi=1;
                break;
                case 'i':
                    x2=8;
                    vmi=1;
                break;
                case 'j':
                    x2=9;
                    vmi=1;
                break;
                default:
                    printf("Ilyet betut nem adhatsz meg.");
                    vmi=0;
            }
            if((masodik[1]==NULL)&&(vmi==1))
            {
                printf("Ilyen koordinatat nem adhatsz meg");
                vmi=0;
            }
            else
            {
                y2=masodik[1]-'0';
            }

            if(vmi==1)
            {
                if((y2>=meret)||(x2>=meret))
                {
                    printf("Ez az elem nem a palya resze. Adj meg egy masikat!");
                    vmi=0;
                    scanf("%s",masodik);
                }
                else if((x1==x2)&&(y1==y2))
                {
                    printf("Ez az elem nem egyezhet meg az elozovel. Adj meg egy masikat!");
                    vmi=0;
                    scanf("%s",masodik);
                }
            }
            else
            {
                printf("\nAdd meg ujra a masodik elem koordinatait (pl.:a1)");
                scanf("%s",masodik);
            }
        }
    }


    printf("\n\n\nx  ");
    for(i=0;i<meret;i++)
    {
        printf("%c ",i+97);
    }

    printf("\ny  ");
    for(sor=0;sor<meret;sor++)
    {
        printf("\n%d  ", sor);
        for (j=0; j < meret;j++)
        {
            if(tomb[sor*meret+j]==1)
            {
                printf("%c ",tomb[sor*meret+j]);
                //printf("%c ",' ');
            }
            else if((sor==y1)&&(j==x1))
            {
                printf("%c ",tomb[y1*meret+x1]);
            }
            else if((sor==y2)&&(j==x2))
            {
                printf("%c ",tomb[y2*meret+x2]);
            }
            else if(tomb[sor*meret+j]!=0)
            {
                //printf("%c ",tomb[i*meret+j]);
                printf("%c ",'#');
            }
        }
    }

    if(tomb[y1*meret+x1]==tomb[y2*meret+x2])
    {
        tomb[y1*meret+x1]=1;
        tomb[y2*meret+x2]=1;
        return 1;
    }

    return 0;
}
int is_digitstr(char * str)
{
    int i=1, j=0;
    if(str[0]=='\0')
    {
        return 0;
    }
    j=str[0]-'0';
    while(str[i]!='\0')
    {
        if (str[i]>='0'&& str[i]<='9')
        {
            j=j*10+(str[i]-'0');
            i++;
        }
        else
        {
            return 0;
        }
    }
    return j;
}
