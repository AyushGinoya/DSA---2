#include<iostream>
using namespace std;

const int N=1e3+10;
int gph[N][N]={0};

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        int v1,v2;  // wt---->if wt is given
        cin>>v1>>v2;    // >>wt
        gph[v1][v2]=1;      //1=wt;
        gph[v2][v1]=1;      //1=wt
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<gph[i][j]<<"      ";
        }
        cout<<endl;
    }
}
