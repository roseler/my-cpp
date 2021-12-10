#include<iostream>
#include<windows.h>
#include<conio.h>
#include <time.h>
#define SEC_DELEY 1000
#define SEC 42
#define MINT 2
#define White 32

using namespace std;

    int y,x,i=0;
    char sembol = SEC;

void gotoxy(int column,int row)
{
    COORD coord;
    coord.X = column;
    coord.Y = row;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
void hour(int hour)
{
    switch(hour)
    {
    case 1:  gotoxy(42,7);  cout<<1;   break;
    case 2:  gotoxy(52,12); cout<<2;   break;
    case 3:  gotoxy(62,17); cout<<3;   break;
    case 4:  gotoxy(52,22); cout<<4;   break;
    case 5:  gotoxy(42,27); cout<<5;   break;
    case 6:  gotoxy(31,33); cout<<6;   break;
    case 7:  gotoxy(20,27); cout<<7;   break;
    case 8:  gotoxy(10,22); cout<<8;   break;
    case 9:  gotoxy(0,17);  cout<<9;   break;
    case 10: gotoxy(9,12);  cout<<10;  break;
    case 11: gotoxy(19,7);  cout<<11;  break;
    case 12: gotoxy(31,1);  cout<<12;  break;
    }
}
void printPoint(int mt,char sembol)
{
    if(mt<=15&&mt>0)
    {
        x=31;y=2;
        for(int count=1;count<=mt;count++, x+=2, y++);
        gotoxy(x,y);cout<<sembol;
        sembol = SEC;
    }
    else if(mt<=30&&mt>15)
    {
        x=61;y=17;
        for(int count=16;count<=mt;count++, x-=2, y++);
        gotoxy(x,y);cout<<sembol;
        sembol = SEC;
    }
    else if(mt<=45&&mt>30)
    {
        x=31;y=32;
        for(int count=31;count<=mt;count++, x-=2, y--);
        gotoxy(x,y);cout<<sembol;
        sembol = SEC;
    }
    else if(mt<=60&&mt>45)
    {
        x=1;y=17;
        for(int count=46;count<=mt;count++, x+=2, y--);
        gotoxy(x,y);cout<<sembol;
        sembol = SEC;
    }
}
void sec(int second)
{
    i=0;
    switch(second)
    {
    case 2:
        x=41,y=7;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y++);cout<<" ";
            x+=2;      i++;
        }
        break;
    case 3:
        x=51;y=12;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y++);cout<<" ";
            x+=2;      i++;
        }
        break;
    case 4:
        x=61;y=17;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y++);cout<<" ";
            x-=2;      i++;
        }
        break;
    case 5:
        x=51;y=22;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y++);cout<<" ";
            x-=2;      i++;
        }
        break;
    case 6:
        x=41;y=27;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y++);cout<<" ";
            x-=2;      i++;
        }
        break;
    case 7:
        x=31;y=32;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y--);cout<<" ";
            x-=2;      i++;
        }
        break;
    case 8:
        x=21;y=27;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y--);cout<<" ";
            x-=2;      i++;
        }
        break;
    case 9:
        x=11;y=22;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y--);cout<<" ";
            x-=2;      i++;
        }
        break;
    case 10:
        x=1;y=17;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y--);cout<<" ";
            x+=2;      i++;
        }
        break;
    case 11:
        x=11;y=12;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y--);cout<<" ";
            x+=2;      i++;
        }
        break;
    case 12:
        x=21;y=7;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y--);cout<<" ";
            x+=2;      i++;
        }
        break;
    case 1:
        x=31;y=2;
        while(i<5)
        {
            gotoxy(x,y);cout<<sembol;
            Sleep(SEC_DELEY);
            gotoxy(x,y++);cout<<" ";
            x+=2;      i++;
        }
        break;
    }
}
int convt24To12(int n)
{
    int hour = 1;
    if(n==0)
        return 12;
    for(int i=13; i<n; i++)
        hour++;
    return hour;
}
int main()
{
    int hours;
    /// Center of the Clock
    char Center=236;
    gotoxy(30,16);  cout << Center;
    /// Print All Digit of Clock
    for(int hours=1; hours<=12; hours++)
        hour(hours);
    /// Starting up clock
    while(1)
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        cout<<endl<<" "<<tm.tm_year+1900<<" / "<<tm.tm_mon+1<<" / "<<tm.tm_mday;

        hours=convt24To12(tm.tm_hour);

        for(int minute=tm.tm_min,second; minute<=60; minute++)
        {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            hour(hours);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

            printPoint(minute,MINT);
            for(second=tm.tm_sec; second<=60; second++)
                if(second!=minute)
                {
                    printPoint(second,SEC);
                    Sleep(SEC_DELEY);
                    printPoint(second,White);
                }
                else
                {
                    printPoint(second,SEC);
                    Sleep(SEC_DELEY);
                    printPoint(second,White);
                    printPoint(minute,MINT);
                }
                printPoint(minute,White);
        hour(hours);
    }
    }
    getch();
    return 1;
}
