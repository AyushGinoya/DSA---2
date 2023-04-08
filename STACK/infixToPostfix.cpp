#include<iostream>
#include<stack>
using namespace std;

int isPrio(char c)
{
    if(c=='^')
        return 3;
    else if(c=='+' || c=='-')
        return 1;
    else if(c=='*' || c=='/')
        return 2;
    else
        return 0;
}

void convert(string infix)
{
    stack <char> S;
    string str;

    for(int i=0;i<infix.length();i++)
    {
        if(infix[i]>='a' && infix[i]<='z')
        {
                str=str+infix[i];
        }
        else if(infix[i] == '(')
        {
            S.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(S.top()!='(')
            {
                str=str+S.top();
                S.pop();
            }
            S.pop();
        }
       else
        {
            while(!S.empty() && isPrio(infix[i]) <= isPrio(S.top()))
            {
                //S.push(infix[i]);
                str=str+S.top();
                S.pop();
           }
           S.push(infix[i]);
        }
    }

    while(!S.empty())
    {
        str=str+S.top();
        S.pop();
    }

    cout<<str;
}


int main()
{
    string c="a*b/(c-d)";
    convert(c);

}
