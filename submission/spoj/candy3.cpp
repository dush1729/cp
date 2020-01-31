#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        unsigned long long N,a,s=0,i;
        scanf("%llu",&N);
        for(i=0;i<N;i++)
        {
            scanf("%llu",&a);
            s=(s+a)%N;
        }
        if(s==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
