#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,x,parent[1001],q,u,v;
int main()
{
    int hhh,zzz;
    scanf("%d",&hhh);
    for(zzz=1;zzz<=hhh;zzz++)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) parent[i]=-1;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                parent[x]=i;
            }
        }
        scanf("%d",&q);
        printf("Case %d:\n",zzz);
        while(q--)
        {
            scanf("%d%d",&u,&v);
            set <int> s;
            while(u!=-1)
            {
                s.insert(u);
                u=parent[u];
            }
            while(s.find(v)==s.end()) v=parent[v];
            printf("%d\n",*s.find(v));
        }
    }
    return 0;
}
