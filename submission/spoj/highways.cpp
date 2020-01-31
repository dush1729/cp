#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20,MAX=1e9;
int t,n,m,i,u,v,c,st,ed,dp[N];
vector <pair<int,int>> adj[N];
priority_queue <pair<int,int>> pq;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&st,&ed);
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&c);
            adj[u].push_back({c,v});
            adj[v].push_back({c,u});
        }

        for(i=1;i<=n;i++) dp[i]=MAX;

        dp[st]=0;
        pq.push({0,st});
        while(!pq.empty())
        {
            int c=-pq.top().first, u=pq.top().second;  pq.pop();

            for(auto i:adj[u])
            {
                c=i.first; v=i.second;
                if(dp[v]>dp[u]+c)
                {
                    dp[v]=dp[u]+c;
                    pq.push({-dp[v],v});
                }
            }
        }

        if(dp[ed]==MAX) printf("NONE\n");
        else printf("%d\n",dp[ed]);
    }
}
