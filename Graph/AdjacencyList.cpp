#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class Graph
{
    //Graph(){}
    public:

        unordered_map<int, list<int>> adj;
        void addEged(int a, int b, bool dir)
        {
            adj[a].push_back(b);
            if(dir == 0)
            {
                adj[b].push_back(a);
            }
        }

        void print()
        {
            for(auto i : adj)
            {
                cout<<i.first<<" -> ";
                for(auto j : i.second)
                {
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }
};


int main()
{
    Graph g;
    int n,m;
    cout<<"Enter value of node = ";
    cin>>n;
    cout<<"Enter value of adj =  ";
    cin>>m;

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEged(u,v,0);
    }

    g.print();
}
