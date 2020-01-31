#include<stdio.h>
int main()
{
    int a[8]={},i;
    for(i=0;i<8;i++) scanf("%d",&a[i]);
    while(a[0]!=-1)
    {
        int p,m1;double r,m=0;
        for(i=0;i<4;i++)
        {
            r=a[i]*1.0/a[i+4];
            if(m<r)
            {
                m=r;
                p=i;
            }
        }
        if(a[p]%a[p+4]) m1=m+1;
        else m1=m;
        for(i=0;i<4;i++) printf("%d ",a[i+4]*m1-a[i]);
        printf("\n");
        for(i=0;i<8;i++) scanf("%d",&a[i]);
    }
    return 0;
}
