// C++ program to swap two numbers using 
// pass by value. 
#include <iostream> 
using namespace std; 
void swap(int x, int y) 
{ 
int z = x; 
x = y; 
y = z; 
} 
int main() 
{ 
int a = 45, b = 35; 
cout << "Before Swap\n"; 
cout << "a = " << a << " b = " << b << "\n"; 
swap(a, b); 
cout << "After Swap with pass by reference\n"; 
cout << "a = " << a << " b = " << b << "\n"; 
}

// C++ program to swap two numbers using 
 // pass by reference. 
 #include <iostream> 
2
 using namespace std; 
 void swap(int& x, int& y) 
 { 
 int z = x; 
 x = y; 
 y = z; 
 } 
 int main() 
 { 
 int a = 45, b = 35; 
 cout << "Before Swap\n"; 
 cout << "a = " << a << " b = " << b << "\n"; 
 
 swap(a, b); 
 
 cout << "After Swap with pass by reference\n"; 
 cout << "a = " << a << " b = " << b << "\n"; 
 }
 
 
 //C++ program for passing array as constant pointer
 #include <iostream>
 
 using namespace std;
 int Function1(const int * list, int n)
 {
 for(int i=0;i<n;i++)
 cout<<list[i]<<"\t";
 
 cout<< "Trying to change values of array\t";
 *list[2]++
 cout<<*list[2];
 }; 
 int main()
3
 {
 int const list[5] = {10,20,30,40,50};
 Function1(list,5);
 
 return 0;
 }

