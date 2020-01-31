#include<stdio.h>
unsigned long long z[100][100]={};
unsigned long long c(unsigned long long a,unsigned long long b)
{
    if(z[a][b]!=0) return z[a][b];
    else if(b==0)
    {
        z[a][b]=1;
        return 1;
    }
    else if(a==b)
    {
        z[a][b]=1;
        return 1;
    }
    else
    {
        z[a][b]=(c(a-1,b-1)%10000007)+(c(a-1,b)%10000007);
        return z[a][b];
    }
}
int main()
{
    unsigned long long n,r,ans;
    scanf("%llu%llu",&n,&r);
    if(n>=r)
    {
        ans=c(n-1,r-1)%10000007;
        printf("%llu\n",ans);
    }
    else printf("-1\n");
    return 0;
}
