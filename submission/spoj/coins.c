#include<bits/stdc++.h>
using namespace std;
int n;
map <int,long long> m;
long long f(int x)
{
    if(m.find(x)!=m.end()) return m[x];
    return m[x]=max(0LL+x,f(x/2)+f(x/3)+f(x/4));
}
int main()
{
    while(scanf("%d",&n)!=EOF) m.clear(), printf("%lld\n",f(n));
}
