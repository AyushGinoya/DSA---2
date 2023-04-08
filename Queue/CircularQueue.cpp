#include<iostream>
using namespace std;

class Cqueue
{
    int front;
    int rear;
    int size;
    int *q;
public:
    Cqueue(int s)
    {
        size=s;
        front=rear=-1;
        q=new int[s];
    }

    void enqueue(int x)
    {
        if((rear+1)%size == front)
        {
            cout<<"Queue is full"<<endl;
        }
        else
        {
            if(front == -1)
            {
                front = 0;
            }
            rear = (rear +1)%size;
            q[rear]=x;
        }
    }

    int dequeue()
    {
        int x=-1;
        if(front == rear)
        {
            cout<<"Queue is Empty"<<endl;
        }
        else
        {
            x=q[front];
            if(front==rear)
            {
                front=rear=-1;
            }
            else
            {
                front=(front+1)%size;
            }
        }
        return x;
    }

    void display()
    {
        int i;
        for(i=front;i!=(rear+1)%size;i=(i+1)%size)
        {
            cout<<q[i]<<endl;
        }
    }
};

int main()
{
    Cqueue a(510);
    a.enqueue(5);
    a.enqueue(4);
    a.enqueue(3);
    a.enqueue(2);
    a.enqueue(1);
    a.display();
    cout<<endl<<endl;

    cout<<a.dequeue()<<endl;
    cout<<a.dequeue()<<endl;
     cout<<endl<<endl;

    a.enqueue(20);
    a.enqueue(10);

    a.display();
    cout<<endl<<endl;
}
