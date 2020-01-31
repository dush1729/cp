#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int t,i,j,p[N],a,b,n,pv,cnt;
vector <int> f[11];
int main()
{
    for(i=2;i*i<N;i++)
    {
        if(!p[i])
        {
            for(j=i*i;j<N;j+=i) if(!p[j]) p[j]=i;
        }
    }

    for(i=1;i<N;i++) if(!p[i]) p[i]=i;

    for(i=2;i<N;i++)
    {
        pv=-1;
        cnt=0;
        j=i;
        while(j!=1)
        {
            if(p[j]!=pv) cnt++;
            pv=p[j];
            j/=p[j];
        }
        if(cnt>10) continue;
        f[cnt].push_back(i);
    }

    f[0].push_back(1);

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&n);
        printf("%d\n",upper_bound(f[n].begin(),f[n].end(),b)-lower_bound(f[n].begin(),f[n].end(),a));
    }
}
