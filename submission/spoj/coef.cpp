#include<bits/stdc++.h>
int main()
{
    unsigned long long a[13]={1,1,2,6,24,120},i,K,N,p,x;
    for(i=6;i<13;i++) a[i]=i*a[i-1];
    while(scanf("%llu%llu",&N,&K)!=EOF)
    {
        p=a[N];
        for(i=0;i<K;i++)
        {
            scanf("%llu",&x);
            p/=a[x];
        }
        printf("%llu\n",p);
    }
    return 0;
}
