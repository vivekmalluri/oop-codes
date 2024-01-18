#include<iostream>
using namespace std;
#include<cstdlib>
#include<new>
class matrix
{
int **array;
int row;
int column;
public:
 //default constructor
 matrix()
 {
 array=NULL;
 row=0;
 column=0; 
 }
 //single parameter constructor(square matrix)
 matrix(int length)
 {

 int i,j;
 array=(int **)new int[length];
 row=length;
 column=length;
 for(i=0;i<length;i++)
 array[i]=new int[length];
 for(i=0;i<length;i++)
 for(j=0;j<length;j++)
 array[i][j]=0;
 }
 //double parameterized constructor(rectangular matrix)
 matrix(int r,int c)
 {
 int i,j;
 row=r;
 column=c;
 array=(int **)new int[r];
 for(i=0;i<r;i++)
 array[i]=new int[c];
 for(i=0;i<r;i++)
 for(j=0;j<c;j++)
 array[i][j]=0;
 }
 //copy constructor
 matrix(const matrix &c)
 {
 int i,j;
 cout<<"\nCopy Con\n";
 array=(int **)new int[c.row];
 for(i=0;i<c.row;i++)
 array[i]=new int[c.column];
 row=c.row;
 column=c.column;
 for(i=0;i<c.row;i++)
 for(j=0;j<c.column;j++)
 array[i][j]= c.array[i][j];
 }
//destructor
 ~matrix()
 {
 delete []array;
 }
//Assignment Operator
matrix operator=(const matrix &mat)
{

int i,j;
if(row!=mat.row || column!=mat.column)
{
 cout<<"\n\nAssignment of different matrices is not possible..\n";
 exit(1);
}
for(i=0;i<row;i++)
 for(j=0;j<column;j++)
 array[i][j]=mat.array[i][j];
return (*this);
}
void operator delete[](void *pointer)
{
 free(pointer);
}
friend istream& operator>>(istream &cin,matrix &c);
friend ostream& operator<<(ostream &cout,matrix &c);
};
istream& operator>>(istream &cin,matrix &c)
{
int i,j;
cout<<"\n enter array values"<<endl;
for(i=0;i<c.row;i++)
{
 for(j=0;j<c.column;j++)
 {
 cout<<"\n enter value of array["<<i<<"]["<<j<<"]";
 cin>>c.array[i][j];
 }
}
return cin;
}
ostream& operator<<(ostream &cout,matrix &c)
{
int i,j;
cout<<"\n enter array values"<<endl;
for(i=0;i<c.row;i++)
{
 for(j=0;j<c.column;j++)
 {
 cout<<"\n the value of array["<<i<<"]["<<j<<"]";
 cout<<c.array[i][j];
 }
}
return cout;

}
int main()
{
matrix m1(2),m2(2),m3(2),m5(2);
cout<<"\n enter matrix m1 values";
cin>>m1;
cout<<"\n the values of matrix1 entered are";
cout<<m1;
cout<<"\n enter matrix m2 values";
cin>>m2;
//cout<<m2;
//cin>>m3;
cout<<"\n the values of matrix 2entered are";
cout<<m2;
//m3=m1+m2;
cout<<"\n the values of matrix1 after assignment from m2 are";
m1 = m2; cout<<m1;
cout<<"invoking copy constructor\n";
m5 = m2;
cout<<"Values of Matrix 5 generated using copy constructor with Matrix 2\n";
cout<<m5;
}
