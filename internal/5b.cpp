#include<iostream>
#include<vector>
using namespace std;
class Matrix
{
 int x,y; // redundant class data erased 
 vector< vector <int> > v;
 public:
 Matrix()
 {
 x=0; y=0; 
 v = vector< vector<int> >(x,vector <int>(y, 0)); 
 for(int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 v[i][j]=0;
 }
 }
 }
 Matrix(int m, int n) // Main constructor
 {
 x=m;
 y=n;
 v = vector< vector<int> >(x,vector <int>(y, 0)); 
 cout<< "enter values into the vector" << endl;
 for(int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 cin >> v[i][j];
 }
 }
 }

 Matrix(const Matrix &t)
 {
 x=t.x;
 y=t.y;
 v = vector< vector<int> >(x,vector <int>(y, 0)); 
 //v=t.v;
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 v[i][j] = t.v[i][j];
 }
 }
 cout << "copy constructor called" << endl;
 }
 ~Matrix()
 {
 //cout << "destructor called" << endl;
 }
 bool operator >(const Matrix r)
 {
 if(x!=r.x||y!=r.y)
 {
 cout<<"\nSize Mismatch\n";
 return false;
 }
 else
 {
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 if(v[i][j] <= r.v[i][j])
 return false;
 } } }
 
 return true;
 }
 
 bool operator <(const Matrix r)
 {
 if(x!=r.x||y!=r.y)
 {
 cout<<"\nSize Mismatch\n";
 return false;
 }
else
 {
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 if(v[i][j] >= r.v[i][j])
 return false;
 }
 }
 
 }
 
 return true;
 }
 
 
 bool operator >=(const Matrix r)
 {
 if(x!=r.x||y!=r.y)
 {
 cout<<"\nSize Mismatch\n";
 return false;
 }
 else
 {
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 if(v[i][j] < r.v[i][j])
 return false;
 }
 }
 
 }
 
 return true;
 }
 
 bool operator <=(const Matrix r)
 {
 if(x!=r.x||y!=r.y)
 {
 cout<<"\nSize Mismatch\n";
 return false;
}
 else
 {
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 if(v[i][j] > r.v[i][j])
 return false;
 }
 }
 
 }
 
 return true;
 }
 
 
 bool operator ==(const Matrix r)
 {
 if(x!=r.x||y!=r.y)
 {
 cout<<"\nSize Mismatch\n";
 return false;
 }
 else
 {
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 if(v[i][j] != r.v[i][j])
 return false;
 }
 }
 
 }
 
 return true;
 }
 
 
 void operator ++()
 {
 
 for (int i = 0; i < x; ++i)
{
 for (int j = 0; j < y; ++j)
 {
 v[i][j]++;
 }
 }
 }
 
 void operator +=(const Matrix r)
 {
 if(x!=r.x||y!=r.y)
 {
 cout<<"\nSize Mismatch\n";
 
 }
 else
 {
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 v[i][j] = v[i][j]+ r.v[i][j];
 
 }
 }
 }
 }
 
 Matrix& operator+(const Matrix &r) 
 {
 if(x!=r.x||y!=r.y)
 {
 cout<<"order mismatch to add\n";
 return *this;
 }
 
 //Matrix b;
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 v[i][j] = v[i][j] + r.v[i][j];
 }
 }
 return *this;
 }

 
 
 
 
 Matrix& operator=(const Matrix &r) // needs to output a reference
 {
 if (this == &r) // check self-assignment
 return *this;
 x = r.x;
 y = r.y;
 
 v = vector< vector<int> >(x,vector <int>(y, 0));
 //vector< vector<int> > b(x,vector <int>(y, 0));
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 v[i][j] = r.v[i][j];
 }
 }
 
 return *this;
 }
 void print()
 {
 for (int i = 0; i < x; i++)
 {
 for (int j = 0; j < y; j++)
 {
 cout << v[i][j] << " ";
 }
 cout << endl;
 }
 }
};
int main()
{
 int d1,d2,choice;
 cout << "enter row, column values" << endl;
 cin >> d1 >> d2;
 Matrix ob1;
 Matrix ob2(d1,d2);
 Matrix mat(d1,d2);
 cout << "elements in the matrix using constructor are" << endl;
 ob2.print();
 
 Matrix ob3(ob2);
 cout << "elements in the copy constructor" << endl;
 ob3.print();
 cout << "after overloading assignment operator" << endl;
 Matrix ob4;
 ob4=ob2;
 ob4.print();
 
 
 cout<<"\n Enter 1:>; 2:<; 3:>=; 4:<=; 5: ==; 6:++; 7: +=; 8: +";
 cin>> choice;
 switch(choice)
 {
 case 1: if(mat>ob2)
 cout<<"\nMat is greater\n";
 else 
 cout<<"\nMat is smaller\n";
 break;
 case 2: 
 if(mat<ob2)
 cout<<"\nMat is smaller\n";
 else 
 cout<<"\nMat is greater\n";
 break;
 
 case 3: 
 if(mat>=ob2)
 cout<<"\nMat is greater or equal\n";
 else 
 cout<<"\nMat is smaller\n";
 
 break;
 case 4: 
 if(mat<=ob2)
 cout<<"\nMat is smaller or equal\n";
 else 
 cout<<"\nMat is greater\n";
 break;
 case 5: 
 if(mat==ob2)
 cout<<"\nMat is equal to ob2\n";
 else 
 cout<<"\nMat and ob2 are not equal\n";
 break;
 case 6: cout<<"\n pre incrementor overloading on mat object\n";
 ++mat;
 mat.print();
 break;
 case 7: 
 mat+=ob2;
 cout<<"\nAdding ob2 to mat using += operator overloading\n";
 mat.print();
 break;
 case 8: 
 cout<<"\nAddition operator overloaded\n";
 ob1 = ob2+mat;
 ob1.print();
 break;
 default: cout<<"\nEnter proper option\n";
 
 }
 
 return 0;
}
