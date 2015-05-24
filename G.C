#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int diff;
char s1[4]="hai";
char s2[6]="hai";
for(int i=0;s1!='\0';i++)
{
diff=s1[i]-s2[i];
if(diff!=0)
break;
}
if(diff==0)
{
printf("strings are equal");
}
else
{
printf("strings are not equal");
}
getch();
}