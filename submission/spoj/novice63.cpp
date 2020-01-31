#include<stdio.h>
#include<math.h>
unsigned long long a[61]={},b[60][30]={};
unsigned long long c(unsigned long long n,unsigned long long r)
{
    if(b[n][r]) return b[n][r];
    if((n==r)||(r==0)) return 1;
    b[n][r]=c(n-1,r-1)+c(n-1,r);
    return b[n][r];
}
int main()
{
    a[1]=a[2]=a[3]=1;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        unsigned long long N,p,i;
        scanf("%llu",&N);
        p=log2l(N);
        if(a[p]!=0) printf("%llu\n",a[p]);
        else
        {
            for(i=1;i<=p;i++)
            {
                if(a[i]!=0) continue;
                if(i&1) a[i]=a[i-1];
                else a[i]=a[i-1]+c(i-1,((i/2)-1));
            }
            printf("%llu\n",a[p]);
        }
    }
    return 0;
}
