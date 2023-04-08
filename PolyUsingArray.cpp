#include<iostream>
using namespace std;

class poly
{
    int cof;
    int exp;
public:
    poly()
    {

    }
    void insert(int e,int c)
    {
        exp=e;
        cof=c;
    }

    friend int add(poly p1[],poly p2[],poly p3[],int t1,int t2)
    {
        int i=0,j=0,k=0;

        while(i < t1 && j < t2)
        {
            if(p1[i].exp==p2[j].exp)
            {
                p3[k].exp=p1[i].exp;
                p3[k].cof=p1[i].cof + p2[j].cof;
                i++;
                j++;
                k++;
            }
            else if(p1[i].exp>p2[j].exp)
            {
                p3[k].exp=p1[i].exp;
                p3[k].cof=p1[i].cof;
                i++;
                k++;
            }
            else
            {
                p3[k].exp=p2[j].exp;
                p3[k].cof=p2[j].cof;
                j++;
                k++;
            }
        }

        while(i < t1)
        {
                p3[k].exp=p1[i].exp;
                p3[k].cof=p1[i].cof;
                i++;
                k++;
        }

        while(j < t2)
        {
                p3[k].exp=p2[j].exp;
                p3[k].cof=p2[j].cof;
                j++;
                k++;
        }
        int t=k;
        return t;

    }
        void display()
        {
            cout<<cof<<"X^"<<exp<<"     ";
        }
};

int main()
{
    poly p1[3],p2[3],p3[5];

    p1[0].insert(1,1);
    p1[1].insert(2,2);
    p1[2].insert(3,3);

    p2[0].insert(1,1);
    p2[1].insert(2,2);
    p2[2].insert(3,3);

    int v=add(p1,p2,p3,3,3);

    for(int i=0;i<v;i++)
    {
        p3[i].display();
    }
}
