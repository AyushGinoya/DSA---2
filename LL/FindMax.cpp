#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
}* first=NULL;
int m=0;
void create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}
int max(struct Node*h,int n)
    {
        while(h)
        {
             if(h->data>m)
            {
                m=h->data;
                h=h->next;
            }
        }
        return m;
    }
int main()
{


    int arr[5]={2,4,7,8,9};
    create(arr,5);
    cout<<max(first,5 )<<endl;
}
