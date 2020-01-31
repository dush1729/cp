#include<bits/stdc++.h>
using namespace std;
const int INF=1<<25;
const int N=1e4+9;

typedef pair<int,int> pii; //weight, node
int testcases,v,k,i,x,y,w,source,target;
vector <pair<int,int>> adj[N];
vector <int> dist(N);
int main()
{
    scanf("%d",&testcases);
    while(testcases--)
    {
        scanf("%d%d",&v,&k);
        for(i=0;i<=v;i++) adj[i].clear();
        priority_queue <pii, vector<pii>, greater<pii>> pq;
        for(i=1;i<=k;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            adj[x].push_back({y,w});
        }
        for(i=0;i<=v;i++) dist[i]=INF;
        scanf("%d%d",&source,&target);
        dist[source]=0;
        pq.push({0,source});
        while(pq.empty()==false)
        {
            x=pq.top().first; //weight
            y=pq.top().second;//node
            if(y==target) break;
            pq.pop();
            for(i=0;i<adj[y].size();i++)
            {
                if(dist[adj[y][i].first]>adj[y][i].second+x)
                {
                    dist[adj[y][i].first]=adj[y][i].second+x;
                    pq.push({adj[y][i].second+x,adj[y][i].first});
                }
            }
        }
        if(dist[target]!=INF) printf("%d\n",dist[target]);
        else printf("NO\n");
    }
    return 0;
}
