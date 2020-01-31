#include<stdio.h>
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    if(a%b) return gcd(b,a%b);
    else return b;
}
int main()
{
    short T,t,i;
    scanf("%hd",&T);
    for(i=0;i<T;i++)
    {
        unsigned long long x1,y1,x2,y2,n,d,g;
        scanf("%llu%llu%llu%llu",&x1,&y1,&x2,&y2);
        if((x1==0)&&(y1==0)) printf("Case %hd: 0\n",i+1);
        else
        {
            n=x1*(x2+1)+y1*(y2+1);
            d=(x1+y1)*(x2+y2+1);
            g=gcd(n,d);
            printf("Case %hd: %llu/%llu\n",i+1,n/g,d/g);
        }
    }
    return 0;
}
