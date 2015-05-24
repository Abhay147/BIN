#include<iostream.h>
#include<conio.h>
class A
{
public:
int avar;
};
class B:virtual public A
{
public:
int bvar;
};
class C:virtual public A
{
public:
int cvar;
};
class D:virtual public C,virtual public B
{
int dvar;
};
int main()
{
D obj;
obj.avar=10;
obj.bvar=15;
obj.cvar=23;
return 0;
}