#include<stdio.h>
#include<conio.h>
void main()
{
int a[3][3],b[3][3],c[3][3],i,j,k;
clrscr();
printf("enter the matrix a:");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%d",&a[i][j]);
}}
printf("enter the matrix b:");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%d",&b[i][j]);
}}
printf("multiplication matrix is:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
for(k=0;k<3;k++)
{
c[i][j]=0;
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}}}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%d\t\t",c[i][j]);
}
printf("\n");
}getch();
}