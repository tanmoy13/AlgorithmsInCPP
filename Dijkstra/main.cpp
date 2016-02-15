#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <set>
#include <cmath>
#include <queue>
#include <string>
#define Max 100

using namespace std;

class node
{
    public :
        int x,y,w;
};
vector<int>graph[Max],cost[Max];
struct node
{
    int u,w;
    node(int a, int b)
    {
        u=a;
        w=b;
    }
    bool operator <(const node & p)const
    {
        return w>p.w;
    }
};

int d[Max]={500},parent[Max]={-1};

int dijkstra(int n)
{
    priority_queue < node > q;
    q.push(node(1,0));
    d[1]=0;
    while(!q.empty())
    {
        node top = q.top();
        q.pop();
        int u = top.u;

        if(u==n) return d[u];
        for(int i=0;i<(int)graph[u].size();i++)
        {
            int v=graph[u][i];
            if(d[v]>d[u]+cost[u][i])
            {
                d[v]=d[u]+cost[u][i];
                parent[v]=u;
                q.push(node(v,d[v]));
            }
        }
    }
    return -1;
}
int main()
{
    int M,N;

    while(cin>>M)
    {
        //cin>>N;
        int u,v,w;
        for(int i=1;i<=M;i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        int ret = dijkstra(3);
        if(ret==-1) cout<<"NO Routs"<<endl;
        else cout<<ret<<endl;
    }
}
