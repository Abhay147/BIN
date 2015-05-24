#include<iostream.h>
#include<conio.h>
class customer
{
  private:
  char mobileno[13];
  char name[26];
  char dateofbirth[11];
  char billingadd[51];
  char city[26];
  char phoneno[14];
  float amountoutstanding;
  public:
  void print()
  {
  cout<<endl<<"mobile phone number:";
  cout<<mobileno<<endl;
  cout<<"name"<<endl;
  cout<<name<<endl;
  cout<<"date of birth:"<<endl;
  cout<<dateofbirth<<endl;
  cout<<"billing address:"<<endl;
  cout<<billingadd<<endl;
  cout<<"city:";
  cout<<city<<endl;
  cout<<"amount due:";
  cout<<amountoutstanding<<endl;
  }
  void get()
  {
  cout<< "mobile phone number:";
  cin>>mobileno;
  cout<<endl<<"name:";
  cin>>name;
  cout<<endl<<"billing address:";
  cin>>billingadd;
  cout<<endl<<"city:";
  cin>>city;
  cout<<endl<<"residence phone number;";
  cin>>phoneno;
  cout<<endl<<"amount due:";
  cin>>amountoutstanding;
  }
  };
  int main()
  {
  clrscr();
  customer object;
  object.get();
  object.print();
  getch();
  return 0;
  }