#include<iostream>
#include<vector>
using namespace std;

class Matrix
{
 int x,y; // redundant class data erased
 vector< vector <int> > v;
 public:
 Matrix(): x(0), y(0), v(0)
 {
 }
 Matrix(int m, int n) // Main constructor
 {
 x=m;
 y=n;
 v = vector< vector<int> >(x,vector <int>(y, 0)); // in original version, this class data was redefined locally
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
 v=t.v;
 cout << "copy constructor called" << endl;
 }
 ~Matrix()
 {
 cout << "destructor called" << endl;
 }
 Matrix& operator=(const Matrix &r) // needs to output a reference
 {
 if (this == &r) // check self-assignment
 return *this;
 x = r.x;

 y = r.y;
 vector< vector<int> > b(x,vector <int>(y, 0));
 for (int i = 0; i < x; ++i)
 {
 for (int j = 0; j < y; ++j)
 {
 b[i][j] = r.v[i][j];
 }
 }
 for (int i = 0; i < x; i++)
 {
 for (int j = 0; j < y; j++)
 {
 cout << b[i][j] << " ";
 }
 cout << endl;
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
 int d1,d2;
 cout << "enter row, column values" << endl;
 cin >> d1 >> d2;
 Matrix ob1();
 Matrix ob2(d1,d2);
 cout << "elements in the matrix using constructor are" << endl;
 ob2.print();
 Matrix ob3(ob2);
 cout << "elements in the copy constructor" << endl;

 ob3.print();
 cout << "after overloading assignment operator" << endl;
 Matrix ob4;
 ob4=ob2;
 return 0;
}

