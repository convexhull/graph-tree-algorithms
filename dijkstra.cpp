#include<bits/stdc++.h>
using namespace std;
vector< vector< pair<long long,long long> > > graph;
vector<long long> dijkstra(long long src,int n)
{
    vector<long long>dist(n+1,numeric_limits<long long>::max());
    set< pair<long long,long long> > s;
    dist[src]=0;
    s.insert({dist[src],src});
    while(!s.empty())
    {
        pair<long long,long long> p = *s.begin();
        long long v = p.second;
        s.erase(s.begin());
        for(auto it = graph[v].begin();it!=graph[v].end();it++)
        {
            long long vrt = it->first;
            long long wt = it->second;
            if(dist[v]+wt < dist[vrt])
            {
                if(dist[vrt]!=numeric_limits<long long>::max() )
                {
                    s.erase(s.find({dist[vrt],vrt}));
                    s.insert({dist[v]+wt,vrt});
                }
                else
                    s.insert({dist[v]+wt,vrt});
                dist[vrt] = dist[v]+wt;
            }
        }
    }
    return dist;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    long long T;
    cin>>T;
    while(T--)
    {
        long long n,m;
        cin>>n>>m;
        graph.resize(n+1);
        for(long long i=1;i<=m;i++)
        {
            long long x,y,r;
            cin>>x>>y>>r;
            graph[x].push_back({y,r});
            graph[y].push_back({x,r});
        }
        long long src;
        cin>>src;
        vector<long long>dist = dijkstra(src,n);
        for(long long i=1;i<=n;i++)
            if(i!=src)
                dist[i]!=numeric_limits<long long>::max() ? cout<<dist[i]<<" " : cout<<-1<<" ";
        graph.clear();
        cout<<endl;
    }
	return 0;
}

