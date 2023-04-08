#include<bits/stdc++.h>
#include<stack>
using namespace std;

class Queue
{
private:
    int rear;
    int front;
    int size;
    int *q;
public:
    Queue(int s)
    {
        rear=front=-1;
        size=s;
        q=new int[size];
    }

    void enqueue(int x)
    {
        if(rear>=size-1)
        {
            cout<<"Queue is full"<<endl;
        }
        else
        {
            if(front==-1)
            front++;

            rear++;
            q[rear]=x;
        }
    }

    int dequeue()
    {
        int x=-1;
        if(rear==front || front>rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            x=q[front];
             front++;
        }
        return x;
    }

    void display()
    {
         for(int i=front;i<=rear;i++)
       {
           cout<<q[i]<<endl;
       }
    }

};

int main()
{
    Queue a(10);
    a.enqueue(5);
    a.enqueue(4);
    a.enqueue(3);
    a.enqueue(2);
    a.enqueue(1);

    a.display();
    cout<<endl<<endl;

    cout<<a.dequeue()<<endl;
     cout<<endl<<endl;

    a.display();
    cout<<endl<<endl;

}

