#include<iostream.h>
#include<conio.h>
struct node
{
	int info;
	node *ad;
};
struct node *temp,*first;
class list
{
	public:
	void accept()
	{
		temp->ad=NULL;
		cout<<"Enter 999 to stop"<<endl;
		while(temp->info!=999)
		{
			cout<<"Enter data :\t"<<endl;
			cin>>temp->info;
			temp=temp->ad;
		}
		temp->ad=NULL;
	}
	void display()
	{
		while(temp->ad!=NULL)
		{
			cout<<temp->info<<"\t";
			temp=temp->ad;
		}
	}
};
void main()
{
	clrscr();
	list aj;
	aj.accept();
	aj.display();
	getch();
}