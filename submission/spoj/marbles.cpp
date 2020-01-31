#include<stdio.h>
unsigned long long cal(unsigned long long a,unsigned long long b)
{
    unsigned long long i,p=1;
    if(a/2<b) b=a-b;
    for(i=0;i<b;i++) p=p*(a-i)/(i+1);
    return p;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        unsigned long long n,k,c;
        scanf("%llu%llu",&n,&k);
        c=cal(n-1,k-1);
        printf("%llu\n",c);
    }
    return 0;
}
