#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    //!! Take care of this INF init. Better put it -1 or null(if negative edges). Otherwise choose wisely. Don't use numeric_limits -> overflow  !!!
    vector< vector<int> > dist(n+1,vector<int>(n+1,99999));
    for(int i=1;i<=m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        dist[x][y]=w;
        dist[y][x] = w;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)
                dist[i][j]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j] ) ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
