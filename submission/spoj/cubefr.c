#include<stdio.h>
int a[1000000]={},b[1000000]={},i,j,t;
int main()
{
    for(i=2;i<=100;i++)
    {
        if(a[i]==0)
        {
            t=i*i*i;
            for(j=t;j<=1000000;j+=t) a[j]=1;
        }
    }
    j=1;
    for(i=1;i<=1000000;i++) if(a[i]!=1) {b[i]=j;j++;}
    int T;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        if(a[n]) printf("Case %d: Not Cube Free\n",i+1);
        else printf("Case %d: %d\n",i+1,b[n]);
    }
    return 0;
}
