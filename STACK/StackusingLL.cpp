#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class stack1
{
    node *first;
public:
    stack1()
    {
        first=NULL;
    }

    void creat(int d)
    {
        if(first==NULL)
        {
            node *temp=new node();
            temp->data=d;
            temp->next=first;
            first=temp;
        }
        else
        {
            node *temp=new node();
            temp=first;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            node *t=new node();
            t->data=d;
            temp->next=t;
            temp=temp->next;;
        }
    }

    void push(int x)
    {
        node *temp=new node();
        if(temp==NULL)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            temp->data=x;
            temp->next=first;
            first=temp;
        }
    }

    int pop()
    {
        int x=-1;
        node *temp=new node();
        if(first==NULL)
        {
            cout<<"Stack overflow"<<endl;
        }
        else
        {
            temp=first;
            first=first->next;
            x=temp->data;
            delete temp;
        }
        return x;
    }

    int peak(int pos)
    {
        node *temp=first;
        for(int i=0;i<pos-1&&temp!=NULL ; i++)
        {
            temp=temp->next;
        }
        if(temp!=NULL)
        {
            return temp->data;
        }
        else
        {
            return -1;
        }
    }

    int stacktop()
    {
        if(first)
            return first->data;
        return -1;
    }
    void Display()
    {
        node *c=first;
        while(c!=NULL)
        {
            cout<<c->data<<endl;
            c=c->next;
        }
    }
};

int main()
{
    stack1 s;
    s.creat(1);
    s.creat(2);
    s.creat(3);
    s.creat(4);
    s.creat(5);
    s.Display();
    cout<<endl;
    s.push(11);
    s.Display();
    cout<<endl;
    cout<<s.pop()<<endl<<endl;;
    s.Display();
    cout<<endl;
    cout<<s.peak(3)<<endl<<endl;
    s.Display();
    cout<<endl;
    cout<<s.stacktop()<<endl<<endl;

}
