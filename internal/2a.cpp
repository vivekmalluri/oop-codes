#include <iostream>
using namespace std;
class Complex{
 private:
 int *real;
 int *imag; 
 public:
 Complex()
 {
 real = new int(sizeof(int));
 imag =new int(sizeof(int));
 }
 Complex (int x, int y)
 {
 real = new int(sizeof(int));
 *real=x;
 imag =new int(sizeof(int));
 *imag = y;
 }
 Complex(const Complex &c) //Copy Constructor
 { 
 cout<<"Copy Constructor invoked\n";
 *real= *c.real;
 *imag=*c.imag;
 
 }
 ~Complex()
 {
 free(real);
 free(imag);
 
 }
 void display()
9
 {
 cout<<"Complex Value:\n"<<*real<<"+i"<<*imag;
 }
 void read()
 { int i,r;
 cout<< "enter Real Value\n";
 cin>>r;
 cout<<"enter Imaginary Value\n";
 cin>>i;
 *real=r;
 *imag=i;
 }
 int getreal()
 {
 return *real;
 }
 int getimag()
 {
 return *imag;
 }
 void operator =(const Complex &c) //Assignment Operator
 {
 *this->real= *c.real;
 *this->imag= *c.imag;
 cout<<"Operator Assignment worked\n";
 cout<<*this->real<<"+i"<<*this->imag;
 }
 
};
int main()
{
 Complex c1;
 Complex c2(3,5);
 //c1.read();
 //c1.display();
 c2.display();
 c1 = c2; //assignment operator
 Complex c3=c1;
 c3.display();
 return 0;
 }

