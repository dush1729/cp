#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int i,j,k,ans[N],t,l,r;
bool p[N];
int main()
{
    p[0]=p[1]=true;
    for(i=2;i*i<N;i++)
    {
        if(p[i]) continue;
        for(j=i*i;j<N;j+=i) p[j]=true;
    }

    for(k=1;k<N;k++)
    {
        ans[k]=ans[k-1];
        string a=to_string(k);
        bool ok=true;
        for(i=1;i<(1<<a.size()) and ok;i++)
        {
            string b="";
            for(j=0;j<a.size();j++)
                if(i&(1<<j)) b+=a[j];
            if(!p[stoi(b)]) ok=false;
        }
        ans[k]+=ok;
    }

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        printf("%d\n",ans[r]-ans[l-1]);
    }
}
