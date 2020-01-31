#include<stdio.h>
unsigned a[500001]={},b[3012501]={};
int main()
{
    unsigned i;int t;
    a[0]=0;
    for(i=1;i<=500000;i++)
    {
        t=a[i-1]-i;
        if((t>0)&&(b[t]==0))
        {
            a[i]=t;
            b[t]++;
        }
        else
        {
            a[i]=a[i-1]+i;
            b[a[i-1]+i]=1;
        }
    }
    unsigned k;
    scanf("%u",&k);
    while(k!=-1)
    {
        printf("%u\n",a[k]);
        scanf("%u",&k);
    }
    return 0;
}
