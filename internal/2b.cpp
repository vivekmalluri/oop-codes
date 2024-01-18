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
void operator =(Object const &O1)
{
 for( unsigned int i = 0; i < O1.m_VectorOfInts.size(); i++ )
 {
 m_VectorOfInts[i]=O1.m_VectorOfInts[i];

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
 cout<<"\n Using Assignment Operator in copying an object of vector class\n";
 obj=objCopyCon;
 obj.DisplayVectorContents();
return 0;
}
