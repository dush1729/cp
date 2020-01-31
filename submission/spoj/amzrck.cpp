#include<bits/stdc++.h>
int main()
{
    unsigned a[43]={0,2,3},i;
    for(i=3;i<=43;i++) a[i]=a[i-1]+a[i-2];
    int T;
    scanf("%d",&T);
    while(T--)
    {
        unsigned n;
        scanf("%u",&n);
        printf("%u\n",a[n]);
    }
    return 0;
}
