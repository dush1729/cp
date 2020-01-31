#include<stdio.h>
int main()
{
    short T,a=1;long long r;
    scanf("%d",&T);
    for(;a<=T;a++)
    {
        scanf("%lld",&r);
        printf("Case %d: %.2f\n",a,4*r*r+0.25);
    }
    return 0;
}
