#include<iostream>
#include<vector>
using namespace std;
const int n=1e5+10;
vector<int> gh[n];
vector <bool> vis(n,false);
void dfs(int vertax)
{
    cout<<vertax<<endl;
    vis[vertax]=true;
    for(int child : gh[vertax])
    {
        cout<<"par-"<<vertax<<", child-"<<child<<endl;
        if(vis[child])
            continue;
        dfs(child);
    }
}

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        gh[v1].push_back(v2);
        gh[v2].push_back(v1);
    }
    dfs(1);
}
