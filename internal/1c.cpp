#include<iostream> 
#include<cstring>
using namespace std;
int main()
{ int choice;
 void *ptr;
 
 while(1)
 {
 cout<< "Enter the type of data you would like pointer to handle \t 1-Int,\t 2-Float,\t 3-String,\t 
4-Exit\n";
 cin>> choice;
 switch (choice)
 {
 case 1: { int (*ptr) = new(int);
 *ptr = 25;
 cout<<"pointer handling integer\n";
 cout<<*ptr<<endl;
 break; }
 case 2: {float (*ptr) = new(float);
 *ptr = 25.45;
 cout<<"pointer handling float\n";
 cout<<*ptr<<endl;
 break;
 }
7
 case 3:{ char (*ptr) = new(char);
 *ptr = 'K';
 cout<<"pointer handling integer\n";
 cout<<*ptr<<endl;
 break;}
 case 4: exit(0);
 }
 
 delete(ptr);
 }
}
