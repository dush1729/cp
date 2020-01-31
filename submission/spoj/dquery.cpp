#include<bits/stdc++.h>
using namespace std;
const int N=3e4+20,Q=2e5+20,MAX=1e6+20,SIZE=174;
int n,q,i,a[N],l,r,cl=1,cr=1,f[MAX],ans[Q],cnt;
vector <pair<pair<int,int>,int>> p;
bool cmp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b)
{
    if(a.first.first/SIZE!=b.first.first/SIZE) return a.first.first<b.first.first;
    return a.first.second<b.first.second;
}
void add(int idx)
{
    if(!f[a[idx]]) cnt++;
    f[a[idx]]++;
}
void remove(int idx)
{
    if(f[a[idx]]==1) cnt--;
    f[a[idx]]--;
}
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&l,&r);
        p.push_back({{l,r},i});
    }

    sort(p.begin(),p.end(),cmp);

    for(i=0;i<q;i++)
    {
        l=p[i].first.first; r=p[i].first.second;

        while(cl<l) remove(cl++);
        while(cl>l) add(--cl);
        while(cr>r+1) remove(--cr);
        while(cr<r+1) add(cr++);

        ans[p[i].second]=cnt;
    }

    for(i=0;i<q;i++) printf("%d\n",ans[i]);
}
