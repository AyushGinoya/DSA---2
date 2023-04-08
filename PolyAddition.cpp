#include<iostream>
using namespace std;

class poly;
class term
{
    friend poly;
    int cof;
    int exp;
    term *next;
public:
    term(int c,int e)
    {
        cof=c;
        exp=e;
        next=NULL;
    }
};

class poly
{
    term *first;
public:
    poly()
    {
        first=NULL;
    }

    void createLink(int c,int e)
    {
        if(first==NULL)
        {
            first=new term(c,e);
        }
        else
        {
            term *t=first;
            while(t->next!=NULL)
            {
                t=t->next;
            }
            t->next=new term(c,e);
        }
    }

    term* getFirst()
    {
        return first;
    }

    void addBothPoly(term *first, term *second)
    {
        term *p1=first;
        term *p2=second;

        while(p1!=NULL && p2!=NULL)
        {
            if(p1->exp==p2->exp)
            {
                int c=p1->cof + p2->cof;
                int e=p1->exp;
                this->createLink(c,e);
                p1=p1->next;
                p2=p2->next;
            }
            else if(p1->exp > p2->exp)
            {
                int c=p1->cof;
                int e=p1->exp;
                this->createLink(c,e);
                p1=p1->next;
            }
            else
            {
                int c=p2->cof;
                int e=p2->exp;
                this->createLink(c,e);
                p2=p2->next;
            }
        }

        while(p1)
        {
            int c=p1->cof;
            int e=p1->exp;
            this->createLink(c,e);
            p1=p1->next;
        }

        while(p2)
        {
            int c=p2->cof;
            int e=p2->exp;
            this->createLink(c,e);
            p2=p2->next;
        }
    }

    void display()
    {
        term *t=first;
        while(t!=NULL)
        {
            cout<<t->cof<<"X^"<<t->exp<<"    ";
            t=t->next;
        }
    }
};

int main()
{
    poly p1,p2,p3;
    p1.createLink(1,1);
    p1.createLink(2,2);
    p1.createLink(3,3);
    p1.createLink(4,4);

    p2.createLink(1,1);
    p2.createLink(2,2);
    p2.createLink(3,3);
    p2.createLink(5,5);

    p3.addBothPoly(p1.getFirst(),p2.getFirst());

    p3.display();
}
