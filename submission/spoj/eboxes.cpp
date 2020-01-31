#include<stdio.h>
int main()
{
    short z;
    scanf("%hd",&z);
    while(z--)
    {
        int N,K,T,F;
        scanf("%d%d%d%d",&N,&K,&T,&F);
        printf("%d\n",N+K*((F-N)/(K-1)));
    }
    return 0;
}
