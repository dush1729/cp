#include<stdio.h>
unsigned gcd(unsigned a,unsigned b)
{
    if(a%b) return gcd(b,a%b);
    else return b;
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        unsigned a,b,c;
        scanf("%u%u%u",&a,&b,&c);
        if(c%gcd(a,b)) printf("Case %d: No\n",t+1);
        else printf("Case %d: Yes\n",t+1);
    }
    return 0;
}
