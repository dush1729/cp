#include<stdio.h>
#include<math.h>
unsigned long long a[10000001]={};
int main()
{
    unsigned i,j;
    for(i=2;i<=sqrt(10000000);i++)
    {
        if(a[i]==0) for(j=i*i;j<=10000000;j+=i)
        {
            if(a[j]==0) a[j]=i;
        }
    }
    j=0;
    a[0]=0;a[1]=0;
    for(i=2;i<=10000000;i++)
    {
        if(a[i]==0) a[i]=a[i-1]+i;
        else a[i]=a[i-1]+a[i];
    }
    unsigned short T;
    scanf("%hu",&T);
    while(T--)
    {
        unsigned long long N;
        scanf("%llu",&N);
        printf("%llu\n",a[N]);
    }
    return 0;
}
