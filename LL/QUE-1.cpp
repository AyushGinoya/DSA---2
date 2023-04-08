//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node
{
public:
    int data;
    string s;
    node *next;
};

class Que1
{
    node *first;
    public:
    Que1()
    {
        first=NULL;

    }
     void create(int d,string str)
    {

        if(first==NULL)
        {
            node *temp=new node();
            temp->data=d;
            temp->s=str;
           // temp->next=first;
            first=temp;
            temp->next=NULL;
        }
        else
        {
            node *temp=first;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            node *t=new node();
            t->data=d;
            t->s=str;
            temp->next=t;
            t->next = NULL;
        }
    }
    void insertAfter(int d,string str,int x)
    {
        node *temp=first;
        while(temp->data!=x)
        {
                temp=temp->next;
        }
        node *t=new node();
        t->next=temp->next;
        temp->next=t;
        t->data=d;
        t->s=str;
        //t=temp->next;
    }
    void display()
    {
        node *temp=first;
        while(temp!=NULL)
        {
            cout<<temp->data<<"     ";
            cout<<temp->s<<endl;
            temp=temp->next;
        }
    }
};

int main()
{
    Que1 q;
    q.create(1,"AYUSH");
    q.create(2,"DEEP1");
    q.create(3,"DEEP2");
    q.create(4,"DEEP3");
    q.display();
    cout<<endl;
    q.insertAfter(5,"RAJ",3);
    q.display();
}
