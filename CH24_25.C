#include<stdio.h>
#include<conio.h>
struct st
{
char c[5];
};
void  main()
{
clrscr();
struct st s;
scanf("%s",s.c);
FILE*pt;
pt=fopen("ss.txt","w");
fwrite(&s,sizeof(s),1,pt);
getch();
}


