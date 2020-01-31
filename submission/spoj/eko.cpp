#include<stdio.h>
long long a[1000000],N,M,i,lo=0,hi=0,mid,s,ans,v=0;
long long wood(long long h)
{
    while(lo<hi)
    {
        s=0;
        mid=(lo+hi)/2;
        for(i=0;i<N;i++) if(a[i]>mid) s+=a[i]-mid;
        if(s<M) hi=mid;
        else if(s>M)
        {
            lo=mid+1;
            v=mid;
        }
        else
        {
            v=mid;
            break;
        }
    }
    return v;
}
int main()
{
    scanf("%lld%lld",&N,&M);
    for(i=0;i<N;i++)
    {
        scanf("%lld",&a[i]);
        if(hi<a[i]) hi=a[i];
    }
    mid=(lo+hi)/2;
    ans=wood(mid);
    printf("%lld\n",ans);
    return 0;
}
