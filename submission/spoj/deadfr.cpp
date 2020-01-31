#include<stdio.h>
#include<string.h>
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
    if(a%b) return gcd(b,a%b);
    else return b;
}
int main()
{
    while(1)
    {
        char a[40];unsigned long long i,j,n,d,l,dif,n2,d2,k,n3,d3,g,mn,md=9223372036854775807;
        fflush(stdin);
        scanf("%s",a);
        if((a[0]=='0')&&(a[1]=='\0')) break;
        l=strlen(a);
        for(i=l-4;i>=2;i--)
        {
            n=0;
            d=1;
            for(j=2;j<=i-1;j++)
            {
                n=10*n+a[j]-'0';
                d*=10;
            }
            dif=l-3-i;
            n2=n;
            d2=d;
            for(k=1;k<=dif;k++)
            {
                n2=10*n2+a[j]-'0';
                d2*=10;
                j++;
            }
            n3=n2-n;
            d3=d2-d;
            g=gcd(n3,d3);
            n3/=g;
            d3/=g;
            if(md>d3)
            {
                md=d3;
                mn=n3;
            }
        }
        printf("%llu/%llu\n",mn,md);
    }
    return 0;
}
