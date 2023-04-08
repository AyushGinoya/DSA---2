#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

class QueueLL
{
    node *front,*rear;
    public:
    QueueLL()
    {
        front=rear=NULL;
    }

    void enqueue(int x)
    {
        node *t=new node();
        if(t==NULL)
        {
            cout<<"Queue is Full"<<endl;
        }
        else
        {
            t->data=x;
            t->next=NULL;
            if(front==NULL)
            {
                front=rear=t;
            }
            else
            {
                rear->next=t;
                rear=t;
            }
        }
    }

    int dequeue()
    {
        int x=-1;
        if(front==NULL)
        {
            cout<<"Empty"<<endl;
        }
        else
        {
            node *temp=front;
            x=front->data;
            front=front->next;
            free(temp);
        }

        return x;
    }

    void display()
    {
        node *temp=front;
        while(temp!=NULL)
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    QueueLL v;
    v.enqueue(11);
    v.enqueue(22);
    v.enqueue(33);
    v.enqueue(44);
    v.enqueue(55);

    v.display();

    cout<<endl<<v.dequeue()<<endl<<endl;
}
