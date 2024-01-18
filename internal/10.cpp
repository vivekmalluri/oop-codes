#include <iostream>
using namespace std;
class numb
{ int a,b;
public:
 virtual void read(istream& is) 
{
cout<<"\nEnter two numbers\n";
cin>>a;
cin>>b;
}
 virtual void print(ostream& os) const 
{
cout<<a<<"\t";
cout<<b<<"\n";
}
};
class complex1: public numb
{ int real,imag;
public:
 void read(istream& is) 
{ 
cout<<"\nEnter Real and Imaginary values\n";
cin>> real;
cin>>imag;
}
 void print(ostream& os) const {
cout<<real<<"+i";
cout<<imag; 
}
};
istream& operator>>(istream& is, numb& s)
{
s.read (is); 
return is;
}
ostream& operator<<(ostream& os, const numb& s)
{
s.print(os); 
return os;
}
istream& operator>>(istream& is, complex1& c1)
{
c1.read (is);
return is;
}
ostream& operator<<(ostream& os, const complex1& c1)
{
c1.print(os);
return os;
}
int main( )
 {
 numb *sptr;
 numb s;
cin>>s;
 cout<<s;
 complex1 c1;
cin>>c1;
 cout<<c1;
 return 0; 
}
