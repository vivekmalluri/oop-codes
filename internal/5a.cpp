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
 matrix ()
 {
 array = NULL;
 row = 0;
 column = 0;
 }
 //single parameter constructor(square matrix)
 matrix (int length)
 {
 int i, j;
 array = (int **) new int[length];
 row = length;
 column = length;
 for (i = 0; i < length; i++)
 array[i] = new int[length];
 for (i = 0; i < length; i++)
  for (j = 0; j < length; j++)
   array[i][j] = 0;
 }
 //double parameterized constructor(rectangular matrix)
 matrix (int r, int c)
 {
 int i, j;
 row = r;
 column = c;
 array = (int **) new int[r];
 for (i = 0; i < r; i++)
 array[i] = new int[c];
 for (i = 0; i < r; i++)
 for (j = 0; j < c; j++)
array[i][j] = 0;
 }
 //copy constructor
 matrix (const matrix & c)
 {
 int i, j;
 array = (int **) new int[c.row];
 for (i = 0; i < c.row; i++)
 array[i] = new int[c.column];
 row = c.row;
 column = c.column;
 for (i = 0; i < c.row; i++)
 for (j = 0; j < c.column; j++)
array[i][j] = c.array[i][j];
 }
 //destructor
 ~matrix ()
 {
 delete[]array;
 }
 //OVerloading matrix "+" operation
 matrix operator+ (const matrix & c)
 {
 int i, j;
 matrix temp;
 if (row != c.row || column != c.column)
 {
cout << "\n addition is not possible";
exit (1);
 }
 temp.row = row;
 temp.column = column;
 temp.array = (int **) new int[row];
 for (i = 0; i < row; i++)
 temp.array[i] = new int[column];
 for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
temp.array[i][j] = array[i][j] + c.array[i][j];
 return temp;
 }
 void operator+= (const matrix & c)
 {
 int i, j;
 matrix temp;
 if (row != c.row || column != c.column)
 {
cout << "\n addition is not possible";
exit (1);
 }
 for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
array[i][j] = array[i][j] + c.array[i][j];
 }
 matrix operator= (const matrix & mat)
 {
 int i, j;
 if (row != mat.row || column != mat.column)
 {
cout << "\n\nAssignment of different matrices is not possible..\n";
exit (1);
 }
for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
array[i][j] = mat.array[i][j];
 return (*this);
 }
 int operator == (const matrix & mat)
 {
 int i, j, E = 1;
 if (row != mat.row || column != mat.column)
 {
cout << "\n\ndifferent matrices..\n";
exit (1);
 }
 else
 {
for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
 if (array[i][j] != mat.array[i][j])
 E = 0;
 }
 return E;
 }
 int operator >= (const matrix & mat)
 {
 int i, j, GE = 1;
 if (row != mat.row || column != mat.column)
 {
cout << "\n\ndifferent matrices..\n";
exit (1);
 }
 else
 {
for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
 if (array[i][j] < mat.array[i][j])
 GE = 0;
 }
 return GE;
 }
 int operator<= (const matrix & mat)
 {
 int i, j, LE = 1;
 if (row != mat.row || column != mat.column)
 {
cout << "\n\ndifferent matrices..\n";
exit (1);
 }
 else
 {
for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
 if (array[i][j] > mat.array[i][j])
 LE = 0;
 }
 return LE;
 }
 int operator> (const matrix & mat)
 {
 int i, j, G = 1;
 if (row != mat.row || column != mat.column)
 {
cout << "\n\ndifferent matrices..\n";
exit (1);
 }
 else
 {
for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
 if (array[i][j] <= mat.array[i][j])
 G = 0;
 }
 return G;
 }
 int operator< (const matrix & mat)
 {
 int i, j, L = 1;
 if (row != mat.row || column != mat.column)
 {
cout << "\n\ndifferent matrices..\n";
exit (1);
 }
else
 {
for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
 if (array[i][j] > mat.array[i][j])
 L = 0;
 }
 return L;
 }
 matrix operator- (const matrix & c)
 {
 int i, j;
 matrix temp;
 if (row != c.row || column != c.column)
 {
cout << "\n addition is not possible";
exit (1);
 }
 temp.array = (int **) new int[row];
 for (i = 0; i < row; i++)
 temp.array[i] = new int[column];
 for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
temp.array[i][j] = array[i][j] - c.array[i][j];
 temp.row = row;
 temp.column = column;
 return temp;
 }
 matrix operator+ (int value)
 {
 int i, j;
 matrix temp;
 temp.array = (int **) new int[row];
 for (i = 0; i < row; i++)
 temp.array[i] = new int[column];
 for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
temp.array[i][j] = array[i][j] + value;
 temp.row = row;
 temp.column = column;
 return temp;
 }
 void operator ++ ()
 {
 int i = 0, j = 0;
for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
++(array[i][j]);
 }
 matrix operator- (int value)
 {
 int i, j;
 matrix temp;
 temp.array = (int **) new int[row];
 for (i = 0; i < row; i++)
 temp.array[i] = new int[column];
 for (i = 0; i < row; i++)
 for (j = 0; j < column; j++)
temp.array[i][j] = array[i][j] - value;
 temp.row = row;
 temp.column = column;
 return temp;
 }
 void *operator new[] (size_t size)
 {
 void *pointer = malloc (size);
 return pointer;
 }
 void operator delete[] (void *pointer)
 {
 free (pointer);
 }
 matrix operator () (int r, int c, int ut)
 {
 int i, j;
 matrix temp;
 temp.row = r;
 temp.column = c;
 temp.array = (int **) new int[r];
 for (i = 0; i < r; i++)
 temp.array[i] = new int[c];
 if (ut = 1){
for (i = 0; i < r; i++)
 for (j = 0; j < c; j++)
 if (i < j)
 temp.array[i][j] = 0;
 else
 temp.array[i][j] = 1;
 }
 return temp;
 }
 friend matrix operator+ (int value, matrix c);
 friend matrix operator- (int value, matrix c);
 friend istream & operator>> (istream & cin, matrix & c);
 friend ostream & operator<< (ostream & cout, matrix & c);
};
istream & operator>> (istream & cin, matrix & c)
{
 int i, j;
 cout << "\n enter array values" << endl;
 for (i = 0; i < c.row; i++)
 {
 for (j = 0; j < c.column; j++)
{
 cout << "\n enter value of array[" << i << "][" << j << "]";
 cin >> c.array[i][j];
}
 }
 return cin;
}
ostream & operator<< (ostream & cout, matrix & c)
{
 int i, j;
 cout << "\n enter array values" << endl;
 for (i = 0; i < c.row; i++)
 {
for (j = 0; j < c.column; j++)
{
 cout << "\n the value of array[" << i << "][" << j << "]";
 cout << c.array[i][j];
}
 }
 return cout;
}
matrix
operator+ (int value, matrix c)
{
 matrix temp;
 int i, j;
 temp.array = (int **) new int[c.row];
 for (i = 0; i < c.row; i++)
 temp.array[i] = new int[c.column];
 temp.row = c.row;
 temp.column = c.column;
 for (i = 0; i < c.row; i++)
 for (j = 0; j < c.column; j++)
 temp.array[i][j] = value + c.array[i][j];
 return temp;
}
matrix operator- (int value, matrix c)
{
 matrix temp;
 int i, j;
 temp.array = (int **) new int[c.row];
 for (i = 0; i < c.row; i++)
 temp.array[i] = new int[c.column];
 temp.row = c.row;
 temp.column = c.column;
for (i = 0; i < c.row; i++)
 for (j = 0; j < c.column; j++)
 temp.array[i][j] = value - c.array[i][j];
 return temp;
}
int main ()
{
 int choice,Y=1;
 matrix m1 (3), m2 (2), m3 (2), m4(2),m(3),m5(3),m6(3);

cout<<"\n enter matrix m1 values";
cin>>m1;
cout<<"\nEnter second matrix\n";
cin>>m2;
while(Y) 
{
cout<< "\nEnter 1:>, 2: <, 3: >=, 4:<=, 5: ==, 6: ++, 7:+, 8: +=, 9: ( ) or respective operator overloading.\n";
cin>>choice;
switch(choice) 
{
 case 1: 
 if(m1>m2)
 cout<<"M1 is greater\n";
 else
 cout<<"M2 is greater\n";
 break;
 case 2: 
 if(m1<m2)
 cout<<"M1 is smaller\n";
 else
 cout<<"M2 is smaller\n";
 break;
 
 case 3: m3 = m1 + m2;
 if(m3>=m1)
 cout<<"M3 found to be >= than M1\n";
 else
 cout<<"M3 found to be not >= than M1\n";
 break;
 case 4: 
 m3 = m1 + m2;
 if(m3<=m1)
 cout<<"M3 found to be <= than M1\n";
 else
 cout<<"M3 found to be not <= than M1\n";
break;
 case 5:
 if(m3==m1)
 cout<<"M3 and M1 are equal\n";
 else
 cout<<"M3 and M1 are not equal\n";
 
 break;
 case 6: 
 cout<<"\nIncrementation on Matrix 1\n";
 ++m1;
 cout<<m1;
 break;
 case 7: cout<<"OVerloading + operator on matrces\n"; 
 m4 = m1 + m2;
 cout<<"Matrix 4 created by adding M1 and M2 using + is:\n";
 break;
 case 8: cout<<"overloading shorthand += symbol\n";
 m5 += m1;
 cout<<"Matrix 5 created and using += ith M1 gives:\n";
 cout<<m5;
 break;
 case 9: cout<<"Overloading () operator to create upper triangle Matrix 6\n";
 m6 = m(3,3,1);
 cout<<m6;
 break;
}
 cout<<"\nDo you want to continue?\n";
 cin>>Y;
 if(Y==0)
 break;
}
return 0;
}

