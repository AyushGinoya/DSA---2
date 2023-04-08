#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    node *prev;
    int data;

    node(int d)
    {
        data=d;
        next=prev=NULL;
    }
};


class DoublyLinkList
{
    node *first;
public:
    DoublyLinkList()
    {
        first=NULL;
    }

    void createDoublyLinkList(int d)
    {
        if(first==NULL)
        {
            node *temp=new node(d);
            first=temp;
        }
        else
        {
            node *temp=first;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            node *nn=new node(d);
            temp->next=nn;
            temp=nn;
        }
    }

    void insert_after(int x,int d)
    {
        node *t=new node(d);
        if(first==NULL)
        {
            first=t;
            return;
        }
        else
        {
            node *temp=first;
            while(temp->data!=x)
            {
                temp=temp->next;
            }
            t->prev=temp;
            temp->next->prev=t;
            t->next=temp->next;
            temp->next=t;
        }
    }

    void insert_befor(int x,int d)
    {
            node *t=new node(d);
            node *temp=first;
            while(temp->data!=x)
            {
                temp=temp->next;
            }
            t->prev=temp->prev;
            t->next=temp;
            temp->prev->next=t;
            temp->prev=t;
    }

    void delet_after(int x)
    {
        if(first==NULL)
        {
            cout<<"Empty Link-List"<<endl;
            return;
        }
        node *temp=first;
        while(temp->data!=x)
        {
            temp=temp->next;
        }
        node *t=temp;
        temp->next->next->prev=temp;
        temp->next=temp->next->next;
        delete t;
    }

    void delet_before(int x)
    {
//        if(first==NULL)
//        {
//            cout<<"Empty Link-List"<<endl;
//            return;
//        }
        node *temp=first;
        while(temp->data!=x)
        {
            temp=temp->next;
        }

        temp->prev->prev->next=temp;
        temp->prev=temp->prev->prev;
    }

    void display()
    {
        node *temp=first;
        while(temp!=NULL)
        {
            cout<<temp->data<<"     ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    DoublyLinkList c;
    c.createDoublyLinkList(1);
    c.createDoublyLinkList(2);
    c.createDoublyLinkList(3);
    c.createDoublyLinkList(4);
    c.createDoublyLinkList(5);

    c.insert_after(2,143);

    //c.insert_befor(4,341);    //cheack mistake

    c.delet_after(2);

    c.delet_before(3);
    c.display();
}
