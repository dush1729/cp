#include<bits/stdc++.h>
using namespace std;
const int N=5e5+20;
int t,n,i,j,ans[N];
int main()
{
    for(i=1;i<N;i++) for(j=i<<1;j<N;j+=i) ans[j]+=i;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
}
