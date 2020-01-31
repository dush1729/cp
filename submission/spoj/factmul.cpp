#include<bits/stdc++.h>
unsigned long long mod=109546051211,i,j;
unsigned long long mulmod(unsigned long long a,unsigned long long b)
{
    if((a==0)||(b<mod/a)) return (a*b)%mod;
    unsigned long long x=0,y=a%mod;
    while(b>0)
    {
        if(b%2==1) x=(x+y)%mod;
        y=(y*2)%mod;
        b/=2;
    }
    return x%mod;
}
int main()
{
    unsigned long long n,z=1,fact,a=1;
    scanf("%llu",&n);
    if(n>=587117) printf("0\n");
    else
    {
        for(i=2;i<=n;i++)
        {
            fact=mulmod(i,z);
            z=fact;
            a=mulmod(fact,a);
        }
        printf("%llu\n",a);
    }
    return 0;
}
