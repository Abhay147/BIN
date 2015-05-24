#include<iostream.h>
#include<conio.h>
class student
{
  private:
    char name[20];
    int marks;
  public:
    void get()
    {
      cout<<"\n Enter the name of the student: ";
      cin>>name;
      cout<<"\n Enter the marks of the student: ";
      cin>>marks;
    }
    void compute()
    {
      if(marks<=100 && marks>=75)
	cout<<"\n The grade of the student is A";
      else if(marks<=75 && marks>50)
	cout<<"\n The grade of the student is B";
      else
	cout<<"\n The grade of the student is C";
    }
    void put()
    {
      cout<<"\n Name: "<<name;
      cout<<"\n Marks: "<<marks;
    }
};
void main()
{
  clrscr();
  student s1,s2;
  s1.get();
  s1.put();
  s1.compute();
  s2.get();
  s2.put();
  s2.compute();
  getch();
}


