#include<bits/stdc++.h>
using namespace std;
int main ()
{
    ios::sync_with_stdio(false);
    while(1)
    {
        map <string,int> a;
        map <string,int>::iterator it;
        string b;
        int i,n,m,ma=0,f[20001]={};
        cin>>n>>m;
        if(n==0) break;
        for(i=0;i<n;i++)
        {
            cin>>b;
            a[b]++;
        }
        for(it=a.begin();it!=a.end();it++) f[it->second]++;
        for(i=1;i<=n;i++) printf("%d\n",f[i]);
    }
    return 0;
}
