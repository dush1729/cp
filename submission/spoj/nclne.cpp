#include<stdio.h>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        int n,t=1,i,a;short z=1;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(z&&(t-a>=0)) t=(t-a)<<1;
            else z=0;
        }
        if(z&&(t==0)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
