#include<iostream>
using namespace std;

const int n=100;
class Stack
{
    int *s;
    int top;
    char *c;
public:
    Stack()
    {
        top=-1;
        s=new int[n];
    }
    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            top++;
            s[top]=x;
            cout<<x<<endl;
        }
    }
    int pop()
    {
        int p=-1;
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            p=s[top];
            top--;
        }
        cout<<"top="<<top<<endl;
        return p;
    }

    int peak(int pos)
    {
        int x=-1;
        if(top-pos-1<0)
        {
            cout<<"Invalid number"<<endl;
        }
        else
        {
            x=s[top-pos-1];
        }
        return x;
    }
};

int main()
{
    Stack h;
    h.push(1);
    h.push(2);
    h.push(3);
    h.push(4);
    h.push(5);
    cout<<endl<<endl;
    cout<<h.pop()<<endl;
    cout<<h.pop()<<endl;
    cout<<endl<<endl;
    cout<<h.peak(1)<<endl;
}
