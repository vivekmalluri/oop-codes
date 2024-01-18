#include <iostream>
#include<conio.h>
#include<stdlib.h>
#define MAX_SIZE 5
using namespace std;
// Template Declaration
template<class T>
// Generic Template Class for Search
class TClassSearch {
T x[MAX_SIZE];
T element;
public:
TClassSearch()
 {
 
}
TClassSearch(const TClassSearch &D)
{
 int i = 0;
 for (i = 0; i < MAX_SIZE; i++)
 this->x[i]=D.x[i];
}
void operator = (TClassSearch D)
{
 int i = 0;
 for (i = 0; i < MAX_SIZE; i++)
 this->x[i]=D.x[i];
 
}
 TClassSearch &operator[] (const int i) 
{
 if(i>=MAX_SIZE)
 {
 cout<<"\narray out of bounds\n";
 
 exit(0);
 }
 return x[i];
}
 void readElements() 
 {
 int i = 0;
 for (i = 0; i < MAX_SIZE; i++)
 cin >> x[i];
 //x*=t_x; element=t_element;
 }
 void SearchEle()
 {
cout << "\nEnter Element to Search : ";
 cin>>element;
 }
T getSearch() {
int i;
cout << "\nYour Data :";
for (i = 0; i < MAX_SIZE; i++) {
 cout << "\t" << x[i];
 }
 /* for : Check elements one by one - Linear */
 for (i = 0; i < MAX_SIZE; i++) {
 /* If for Check element found or not */
 if (x[i] == element) {
 cout << "\Class Template Search : Element : " << element << " : Found : Position : " << i 
+ 1 << ".\n";
 break;
 }
 }
 if (i == MAX_SIZE)
 cout << "\nSearch Element : " << element << " : Not Found \n";
}
};

int main() {
 int i;
TClassSearch <int> iMax = TClassSearch<int>();
 TClassSearch <float> fMax = TClassSearch<float>();
 TClassSearch <int> iMax2 = TClassSearch<int>();
 cout << "\nSimple Class Template Array Program Example : Search Number\n";
 cout << "\nEnter " << MAX_SIZE << " \nElements for Searching Int : " << endl;
 iMax.readElements();
 iMax.SearchEle();
 iMax.getSearch();
 cout<<"\n Use of Assignment Operator\n";
 iMax2=iMax;
 cout << " \nEnter Element for Searching Int from iMax2\n : " << endl;
 iMax2.SearchEle();
 iMax2.getSearch();
 cout << "\nEnter " << MAX_SIZE << "\nElements for Searching float : " << endl;
 fMax.readElements(); 
 cout<<"\n Use of Copy constructor\n";
 TClassSearch <float> fCopy = fMax;
 fCopy.SearchEle();
 fCopy.getSearch(); 
 getch();
 return 0;
}

