#include<stdio.h>
int main()
{
    short T;int a,b,c,d,e=1,f=1;
    scanf("%hd",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        for(c=0;c<a;c++)
        {
            scanf("%d",&d);
            if(e<d) e=d;
        }
        for(c=0;c<b;c++)
        {
            scanf("%d",&d);
            if(f<d) f=d;
        }
        if(f>e) printf("MechaGodzilla\n");
        else printf("Godzilla\n");
        e=1;f=1;
    }
    return 0;
}
