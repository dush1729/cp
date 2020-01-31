#include<stdio.h>
unsigned long long gcd(unsigned long long,unsigned long long);
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        unsigned long long n,m,z,s;
        scanf("%llu",&n);
        if(n%2) m=(3*n*n+1)/2;
        else m=3*n*n/2;
        s=6*n*n*n;
        z=gcd(s,m);
        m/=z;s/=z;
        printf("%llu/%llu\n",m,s);
    }
}
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    if(a%b) return gcd(b,a%b);
    else return b;
}
