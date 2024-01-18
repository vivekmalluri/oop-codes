//Stack
#include<iostream>
using namespace std;
class stackdata{
protected:
int stackarray[4],top;
stackdata()
{
top=-1;
}
~stackdata()
{
"Stack destructed!\n";
}
};
class stackfunction:public stackdata{
public:
void push(int n)
{
if (top==3)
cout<<"Stack overflow\n";
else
{
top++;
stackarray[top]=n;
}
}
void pop()
{
if (top==-1)
cout<<"Stack underflow\n";
else
{
cout<<stackarray[top]<<" popped successfully\n";
top--;
}
}
void display()
{
if(top==-1)
cout<<"Stack empty\n";
else
{
for (int i=0;i<=top;i++)
cout<<"Value "<<i+1<<": "<<stackarray[i]<<endl;
}
}
};
int main()
{
stackfunction s1;
char ch;
do{
cout<<"Press...\n"
<<"1 to push\n"
<<"2 to pop\n"
<<"3 to display\n"
<<"4 to exit\n\n";
cin>>ch;
switch(ch)
{
case '1':
int n;
cout<<"Enter element\n";
cin>>n;
s1.push(n);
break;
case '2':
s1.pop();
break;
case '3':
s1.display();
break;
}
}
while(ch!='4');
return 0;
}


//Queue
#include <iostream>
#define MAX 10
using namespace std;
class Queue
{
int front,rear;
int queue[MAX];
public:
 
Queue()
{
front=rear=-1;
70
}
void qinsert(int item)
{
if(rear==MAX-1)
{
cout<<"\nQUEUE OVERFLOW";
}
else if(front==-1 && rear==-1)
{
front=rear=0;
queue[rear]=item;
cout<<"\nITEM INSERTED: "<<item;
}
else
{
rear++;
queue[rear]=item;
cout<<"\nITEM INSERTED: "<<item;
}
}
 
void qdelete()
{
int item;
 
if(rear==-1)
{
cout<<"\nQUEUE UNDERFLOW";
}
else if(front==0 && rear==0)
{
item=queue[front];
front=rear=-1;
cout<<"\n\nITEM DELETED: "<<item;
}
else
{
item=queue[front];
front++;
cout<<"\n\nITEM DELETED: "<<item;
}
}
void qtraverse()
{
71
if(front==-1)
{
cout<<"\n\nQUEUE IS EMPTY\n";
}
else
{
cout<<"\n\nQUEUE ITEMS\n";
for(int i=front;i<=rear;i++)
{
cout<<queue[i]<<" ";
}
cout<<endl;
}
}
};
int main()
{
Queue q;
q.qtraverse();
q.qinsert(10);
q.qinsert(20);
q.qtraverse();
q.qdelete();
q.qinsert(30);
q.qtraverse();
return 0;
}


