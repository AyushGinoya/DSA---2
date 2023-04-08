#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int n=1e5+10;
vector<int> gh[n];
int vis[n];
int level[n];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;

    while(!q.empty())
    {
        int crn_node=q.front();
        q.pop();
        cout<<crn_node<<"       ";
        for(int child : gh[crn_node])
        {
            if(!vis[child])
            {
                vis[child] = 1;
                q.push(child);
                level[child] = level[crn_node] + 1;
            }
        }
    }

}
int main()
{
    int r;
    cin>>r;
    for(int i=0;i<r;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        gh[v1].push_back(v2);
        gh[v2].push_back(v1);
    }

    bfs(1);

    for(int i=1;i<=r;i++)
    {
        cout<<i<<" : "<<level[i]<<endl;
    }
}
