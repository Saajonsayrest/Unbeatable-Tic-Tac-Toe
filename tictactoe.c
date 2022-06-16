#include<stdio.h>
#include<conio.h>
#include<math.h>

int field[3][3],count=0,flag=0,defense=0,invalid=1;

void initial();
void screen();
void check(int);
void move1();
void move2();
void defend();
void attack();
void random();

void main()
{
    int choice;
    char retry;
    re:
    flag=0;
    count=0;
    initial();
    do
    {
        defense=0;
        invalid=1;
        screen();
        printf("Please Enter Your Choice(1-9):");
        scanf("%d",&choice);
        check(choice);
        if(invalid==0)
        {
        attack();
        if(flag==0)
        {
            defend();
            if(defense==0)
            {
                switch (count)
                {
                case 1:
                    move1();
                    break;
                case 2:
                    move2();
                    break;
                case 3:
                    random();
                    break;
                case 4:
                    random();
                    break;
                case 5:
                    flag=1;
                    break;
                }
            }
        }
        }
    }while(flag==0);
    screen();
    if(flag==1)
        printf("\n\t\t\t\tDRAW");
    else
        printf("\n\n\n\t\t\t\tYOU LOSE");
    getch();
    printf("\n\nRetry(Y/N)?");
    retry=getch();
        if(retry=='y'||retry=='Y')
        goto re;
}

void initial()
{
    int i,j,a=1;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            field[i][j]=a;
            a++;
        }
    }
}

void screen()
{
    int i,j;
    system("cls");
    printf("\n\n");
    printf("\t\t\t    Tic Tac Toe");
    printf("\n\n\n\n");
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(field[i][j]==10)
                printf("\t\tO");
            else if(field[i][j]==11)
                printf("\t\tX");
            else
                printf("\t\t%d",field[i][j]);
        }
        printf("\n\n\n\n\n");
    }
}

void check(int x)
{
    int i,j;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(x<10&&field[i][j]==x)
            {
                field[i][j]=10;
                count++;
                invalid=0;
            }
        }
    }
}

void move1()
{
    if(field[2][2]==10)
        {
            field[1][1]=11;
        }
    else
        {
            field[2][2]=11;
        }
}

void move2()
{
    if(field[2][2]==10)
    {
        field[3][1]=11;
    }
    else
    {
        if(field[1][2]==field[3][2]||field[2][1]==field[2][3]||field[2][1]==field[1][2])
            field[1][1]=11;
        else if(field[1][2]==field[2][3])
            field[1][3]=11;
        else if(field[2][3]==field[3][2]||field[1][3]==field[3][2]||field[2][3]==field[3][1])
            field[3][3]=11;
        else if(field[3][2]==field[2][1]||field[1][1]==field[3][2])
            field[3][1]=11;
        else
            random();
    }
}

void defend()
{
    int i,j,a,b,c,d,e,f;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            a=j%3+1;
            b=(j+1)%3+1;
            c=(j+2)%3+1;
            if(field[i+1][a]==10&&field[i+1][b]==10&&field[i+1][c]<10)
                {
                    field[i+1][c]=11;
                    defense=1;
                }
            if(field[a][i+1]==10&&field[b][i+1]==10&&field[c][i+1]<10)
                {
                    field[c][i+1]=11;
                    defense=1;
                }
        }
        a=i%3+1;
        b=(i+1)%3+1;
        c=(i+2)%3+1;
        if(field[a][a]==10&&field[b][b]==10&&field[c][c]<10)
                {
                    field[c][c]=11;
                    defense=1;
                }
        d=abs(2-i)%3+1;
        e=abs(1-i)%3+1;
        f=abs(3-i)%3+1;
        if(field[a][d]==10&&field[b][e]==10&&field[c][f]<10)
                {
                    field[c][f]=11;
                    defense=1;
                }
    }
}

void attack()
{
    int i,j,a,b,c,d,e,f;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            a=j%3+1;
            b=(j+1)%3+1;
            c=(j+2)%3+1;
            if(field[i+1][a]==11&&field[i+1][b]==11&&field[i+1][c]<10)
                {
                    field[i+1][c]=11;
                    flag=2;
                }
            if(field[a][i+1]==11&&field[b][i+1]==11&&field[c][i+1]<10)
                {
                    field[c][i+1]=11;
                    flag=2;
                }
        }
        a=i%3+1;
        b=(i+1)%3+1;
        c=(i+2)%3+1;
        if(field[a][a]==11&&field[b][b]==11&&field[c][c]<10)
                {
                    field[c][c]=11;
                    flag=2;
                }
        d=abs(2-i)%3+1;
        e=abs(1-i)%3+1;
        f=abs(3-i)%3+1;
        if(field[a][d]==11&&field[b][e]==11&&field[c][f]<10)
                {
                    field[c][f]=11;
                    flag=2;
                }
    }
}

void random()
{
   int i,j,b=0;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(field[i][j]<10&&b==0)
                {
                    field[i][j]=11;
                    b=1;
                }
        }
    }
}
