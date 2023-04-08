#include<iostream>
using namespace std;

class LL;
class node
{
    friend LL;
    node *next;
    int data;
};

class LL
{
    node *first;

public:
    LL()
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
            temp=temp->next;
        }
    }

    void insertend(int x)
    {
        node *temp=first;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        node *t=new node();
        temp->next=t;
        t->data=x;
        t->next=NULL;
    }

    void insert_After(int x,int d)
    {
        node *temp=first;
        if(first==NULL)
        {
            temp=first;
        }
        else
        {
            node *nm=new node();
            while(temp->data!=x)
            {
                temp=temp->next;
            }
            nm->next=temp->next;
            temp->next=nm;
            nm->data=d;
            nm=temp->next;
        }
    }

    void insert_Before(int x,int d)
    {
        node *temp=first;
        node *nm=new node();
        while(temp->next->data!=x)
            {
                temp=temp->next;
            }
            nm->data=d;
            nm->next=temp->next;
            temp->next=nm;
    }

    void delete_After(int x)
    {
        node *temp=first;
        while(temp->next->data!=x)
        {
            temp=temp->next;
        }
        node *t=temp->next;
      temp->next=temp->next->next;
      delete t;
    }

    void delete_Before(int d)
    {
        node *temp=first;
        while(temp->next->next->data!=d)
        {
            temp=temp->next;
        }
        node *t=temp->next;
        temp->next = temp->next->next;
        delete t;
    }

    void delete_first()
    {
        node *t=first;
        first=first->next;

        delete t;
    }

    int max=0;
    void find_Max()
    {
        node *temp=first;
        while(temp->next!=NULL)
        {
            if(temp->data>max)
            {
                max=temp->data;
            }
            temp=temp->next;
        }
        cout<<"maximum element is="<<max<<endl;
    }

    void getNthele(int x)
    {
        node *temp=first;

        for(int i=0;i<x-1;i++)
        {
            temp=temp->next;
        }
        cout<<"Nth element is="<<temp->data<<endl;
    }

    int c=0;
    void midele()
    {
        node *temp=first;
        while(temp->next!=NULL)
        {
            c++;
            temp=temp->next;
        }
        temp=first;
        for(int i=0;i<c/2;i++)
        {
            temp=temp->next;
        }
        cout<<"Mid element is="<<temp->data<<endl;

    }

    void reverse_LL()
    {
        node *temp;
        node *prev=NULL;
        node *current=first;

        while(current!=NULL)
        {
            temp=current->next;
            current->next=prev;

            prev=current;
            current=temp;
        }

        first=prev;
    }

    void sort_LL()
    {
        node *temp=first;
        for(int i=0;i<c-1;i++)
        {
                for(int j=0;j<c;j++)
                {
                    if(temp->data>temp->next->data)
                {
                    node *t=new node;
                    t->data=temp->data;
                    temp->data=temp->next->data;
                    temp->next->data=t->data;
                }
                temp=temp->next;
                }
        }
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
    LL l1;
    l1.creat(5);
    l1.creat(4);
    l1.creat(3);
    l1.creat(2);
    l1.creat(1);
    l1.Display();
    cout<<endl<<endl;

    l1.insertend(10);
    l1.Display();
    cout<<endl<<endl;

    l1.insert_After(4,40);
    l1.Display();
    cout<<endl<<endl;

    l1.insert_Before(3,30);
    l1.Display();
    cout<<endl<<endl;

    l1.delete_After(30);
    l1.Display();
    cout<<endl<<endl;

    l1.delete_first();
    l1.Display();
    cout<<endl<<endl;

    l1.find_Max();
    cout<<endl<<endl;

    l1.getNthele(5);
    cout<<endl<<endl;

    l1.midele();
    cout<<endl<<endl;

    l1.reverse_LL();
    l1.Display();
    cout<<endl<<endl;

    l1.sort_LL();
    l1.Display();
    cout<<endl<<endl;
}

/*

#include<iostream>
using namespace std;

class LL;
class node
{
    friend LL;
    node *next;
    int data;
public :
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

class LL
{
    node *first;

public:
    LL()
    {
        first=NULL;
    }
    void creat(int d)
    {
        if(first==NULL)
        {
            first=new node(d);
        }
        else
        {
            node *temp=first;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new node(d);
        }
    }

    void insert_After(int x,int d)
    {
        node *temp=first;
        node *nn=new node(d);

        if(temp==NULL)
        {
            temp=first;
        }

        while(temp->data!=x)
            temp=temp->next;

        nn->next=temp->next;
        temp->next=nn;

        temp=nn;
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
    LL l1;
    l1.creat(5);
    l1.creat(4);
    l1.creat(3);
    l1.creat(2);
    l1.creat(1);
    l1.Display();
    cout<<endl<<endl;

     l1.insert_After(4,40);
    l1.Display();
    cout<<endl<<endl;
}

*/
