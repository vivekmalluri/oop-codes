#include<iostream> 
#include<cstring>
using namespace std;
void conc(char *, char *);
void conc(char *, char *, int);
void copy(char *, char *);
void copy(char *, char *, int);
void copy(char *source, char *destn)
{
 
 destn=source;
4
 
 cout<<"After copy\n";
 cout<<source<<"\t"<<destn<<"\n";
}
void copy(char *source, char *destn, int n)
{
 int i;
 
 for(i=0;i<n; i++)
 destn[i] = source[i];
 
 cout<<"After copy\n";
 cout<<source<<"\t"<<destn<<"\n";
 
}
void conc(char *x,char *y)
{
int p;
for(p=0; x[p] != '\0'; p++);//pointing to the index of the last character of x
 
 for(int q=0; y[q] != '\0'; q++,p++)
 {
 x[p]=y[q];
 }
 
 x[p]='\0';
 cout<<"Concatenated String:\n";
 cout<<x<<endl;
}
void conc(char *dest, char *source, int n)
{
int p;
for(p=0; dest[p] != '\0'; p++);//pointing to the index of the last character of destination
 
 for(int q=0; q<n; q++,p++)
 {
 dest[p]=source[q];
 }
 
 dest[p]='\0';
 cout<<"Concatenated String:\n";
 cout<<dest<<endl;
}
5
int main()
{
 int n;
 char x[100], y[100],z[100];
 cout<<"String 1:\n";
 cin>>x;
 
 cout<<"String 2:\n";
 cin>>y;
 conc(x,y);
 
 cout<<"Enter the source string for N character concatanation";
 cin>>z;
 cout<<"String concatanation of N characters";
 cout<<"Enter N";
 cin>>n;
 conc(x,z,n);
 
 cout<<"Enter strings to be copied Source & Destination\n";
 cin>>x;
 cin>>y;
 copy(x,y);
 cout<<"Enter number of characters to be copied from source\n";
 cin>>n;
 copy(x,y,n);
 
 
 return 0;
}

