#include<stdio.h>
long gcd(long,long);
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        long x,y,z,g;
        scanf("%ld%ld%ld",&x,&y,&z);
        if(x>y) g=gcd(x,y);
        else g=gcd(y,x);
        if((z>x)&&(z>y)) printf("NO\n");
        else if(z%g==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
long gcd(long a,long b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
