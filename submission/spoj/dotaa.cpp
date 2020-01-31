#include<stdio.h>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        int i,n,H,m,D,z=0;
        scanf("%d%d%d",&n,&m,&D);
        for(i=0;i<n;i++)
        {
            scanf("%d",&H);
            z=z+((H-1)/D);
        }
        if(z>=m) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
