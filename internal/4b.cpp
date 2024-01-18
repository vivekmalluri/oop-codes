#include <iostream>
#include <vector>
using namespace std;
class Object
{
 private:
std::vector<int> m_VectorOfInts;
public:
Object()
{
 
}
~Object()
{
 
}
Object(const Object &O1) 
{
 
m_VectorOfInts=O1.m_VectorOfInts;
 
}
int operator>(Object const &O1)
{
 for( unsigned int i = 0; i < O1.m_VectorOfInts.size(); i++ )
 {
 if(m_VectorOfInts[i]<=O1.m_VectorOfInts[i])
 { 
 return 0;
 }
 }

 cout<<"\n The vector is greater\n";
 return 1;
}
int operator>=(Object const &O1)
{
 for( unsigned int i = 0; i < O1.m_VectorOfInts.size(); i++ )
 {
 if(m_VectorOfInts[i]<O1.m_VectorOfInts[i])
 { 
 return 0;
 }
 }
 cout<<"\n The vector is greater\n";
 return 1;
}
int operator<(Object const &O1)
{
 for( unsigned int i = 0; i < O1.m_VectorOfInts.size(); i++ )
 {
 if(m_VectorOfInts[i]>=O1.m_VectorOfInts[i])
 { 
 return 0;
 }
 }
 cout<<"\n The vector is greater\n";
 return 1;
}
int operator<=(Object const &O1)
{
 for( unsigned int i = 0; i < O1.m_VectorOfInts.size(); i++ )
 {
 if(m_VectorOfInts[i]>O1.m_VectorOfInts[i])
 { 
 return 0;
 }
 }
 cout<<"\n The vector is greater\n";
 return 1;
}
int operator==(Object const &O1)
{
 for( unsigned int i = 0; i < O1.m_VectorOfInts.size(); i++ ) {
 if(m_VectorOfInts[i]!=O1.m_VectorOfInts[i])
 { 
 return 0;
 }
 }
 cout<<"\n The vector is greater\n";
 return 1;
}
void operator +=(Object const &O1)
{
 for( unsigned int i = 0; i < O1.m_VectorOfInts.size(); i++ )
 {
 m_VectorOfInts[i]= m_VectorOfInts[i] + O1.m_VectorOfInts[i];
 }
 
} 
void operator ++()
{
 for( unsigned int i = 0; i <m_VectorOfInts.size(); i++ )
 {
 m_VectorOfInts[i]= m_VectorOfInts[i] +1;
 }
 
} 
void AddInt(int num)
{
m_VectorOfInts.push_back(num);
}
std::vector<int> GetCopyOfVector()
{
return m_VectorOfInts;
}
void DisplayVectorContents()
{
for( unsigned int i = 0; i < m_VectorOfInts.size(); i++ )
{
std::cout << "Element[" << i << "] = " << m_VectorOfInts[i] << 
std::endl;
}
std::cout << std::endl;
}

};
int main()
{
 int choice;
// Create our class an add a few ints
Object obj,obj1;
obj.AddInt(32);
obj.AddInt(56);
obj.AddInt(21);
 obj1.AddInt(320);
obj1.AddInt(560);
obj1.AddInt(210);
// Display the vector contents so far
obj.DisplayVectorContents();
 obj1.DisplayVectorContents();
 cout<<"\n Using Copy constructor creating an object of vector class\n"; 
Object objCopyCon(obj1);
objCopyCon.DisplayVectorContents();
 cout<<"\n Choose operation 1. >, 2.>=, 3. <, 4. <=,5.==, 6. +=, 7. ++ \n";
 cin>>choice;
 switch (choice)
 {
 case 1: if(obj1>obj)
 {
 cout<<"\n Yes greater\n";
 }
 else
 cout<<"\n Not greater than\n";
 break;
 case 2: if(obj1>=obj)
 {
 cout<<"\n Yes greater\n";
 }
 else
 cout<<"\n Not greater than\n";
 break;
 
 case 3: if(obj1<obj)
 {
 cout<<"\n Yes Smaller\n";
 }
 else
 cout<<"\n Not smaller than\n";
 break;
 
 case 4: if(obj1<=obj)
 {
 cout<<"\n Yes lessthan equal\n";
 }
 else
 cout<<"\n Not lessthan equal\n";
 break;
 
 case 5: if(obj1==obj)
 {
 cout<<"\n Yes Equal\n";
 }
 else
 cout<<"\n Not Equal\n";
 break;
 
 case 6: obj1+=obj;
 obj1.DisplayVectorContents();
 break;
 case 7: ++obj;
 cout<<"\n values after pre incrementation of obj\n";
 obj.DisplayVectorContents();
 break;
 
 default: cout<<"\n enter proper choice\n"; 
 }
return 0;
}

