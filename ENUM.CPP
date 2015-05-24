#include<iostream.h>
#include<conio.h>
void main()
{
   clrscr();
   enum
   {
      monday,tuesday,wednesday,thursday,friday,saturday,sunday
   }day;
   day=monday;
   if(day==saturday || day==sunday)
      cout<<"\n Day is a weekend day";
   else if(day==wednesday)
      cout<<"\n Day is a hump day middle of the work week";
  else
     cout<<"\n Invalid day";
   getch();
   //return 0;
}
