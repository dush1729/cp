#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int c,f,i,j,x,y,z,id[N];
vector <pair <int,pair<int,int>>> p;
int root(int x)
{
    while(id[x]!=x)
    {
        id[x]=id[id[x]];
        x=id[x];
    }
    return x;
}
void union1(int x,int y)
{
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}
long long kruskal()
{
    long long minimumCost=0;
    for(i=0;i<p.size();++i)
    {
        x=p[i].second.first;
        y=p[i].second.second;
        z=p[i].first;
        if(root(x)!=root(y))
        {
            minimumCost+=z;
            union1(x,y);
        }
    }
    return minimumCost;
}
int main()
{
    scanf("%d%d",&c,&f);
    for(i=1;i<=c;i++) id[i]=i;
    for(i=0;i<f;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        p.push_back({z,{x,y}});
    }
    sort(p.begin(),p.end());
    printf("%lld",kruskal());
    return 0;
}
