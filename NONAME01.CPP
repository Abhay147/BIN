#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
char s1[5]="hai";
char s2[5]="HAI";
int c;
c=strcmp(s1,s2);
if(c==0)
{
printf("equal");
}
else
{
printf("not equal");
}
getch();
}