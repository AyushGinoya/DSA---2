#include<iostream>
using namespace std;

sortPath(int arr[][3])
{
    int t[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            t[i][j]=arr[i][j];
        }
    }

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    if(t[j][i] + t[i][k] < t[j][k])
                    {
                        t[j][k] = t[j][i] + t[i][k];
                    }
                }
            }
        }

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<t[i][j]<<"    ";
            }
            cout<<endl;
        }
}
int main()
{
    int a[3][3] = {
                            {0,4,11},{6,0,2},{3,INT_MAX,0}
                        };
    sortPath(a);
}
