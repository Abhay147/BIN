#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int m1,m2,m3,rol,tot,avg;
char name[20];
printf("enter the name:");
scanf("%s",name);
printf("enter the roll no.:");
scanf("%d",&rol);
printf("enter the marks");
scanf("%d%d%d",&m1,&m2,&m3);
tot=m1+m2+m3;
avg=tot/3;
printf("name:%s",name);
printf("roll no:%d",rol);
printf("marks:%d%d%d",m1,m2,m3);
printf("total:%d",tot);
printf("avgerage:%d",avg);
getch();
}
