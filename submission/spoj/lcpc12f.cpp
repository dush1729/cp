#include<stdio.h>
int main()
{
    unsigned t,T;
    scanf("%u",&T);
    for(t=0;t<T;t++)
    {
        unsigned x,n,i,a[2001]={},v;unsigned long long c=0;
        scanf("%u%u",&x,&n);
        for(i=0;i<n;i++)
        {
            scanf("%u",&v);
            if(v>x) continue;
            c+=a[v];
            a[x-v]++;
        }
        printf("%u. %llu\n",t+1,c);
    }
    return 0;
}
