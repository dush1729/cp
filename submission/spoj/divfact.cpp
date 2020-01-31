#include<stdio.h>
#include<math.h>
int main()
{
    unsigned short a[50001]={},b[5133]={},i,j,T;
    for(i=2;i<=sqrt(50000);i++)
    {
        for(j=i*i;j<=50000;j+=i) a[j]=1;
    }
    j=0;
    for(i=2;i<=50000;i++) if(a[i]!=1) {b[j]=i;j++;}
    scanf("%hu",&T);
    while(T--)
    {
        unsigned N,pr,y;unsigned long long z=1;
        scanf("%u",&N);
        for(i=0;(b[i]<=N)&&(i<=5132);i++)
        {
            y=0;
            for(pr=b[i];pr<=N;pr*=b[i])
            {
                y+=N/pr;
            }
            z*=y+1;
            z%=1000000007;
        }
        z%=1000000007;
        printf("%llu\n",z);
    }
    return 0;
}
