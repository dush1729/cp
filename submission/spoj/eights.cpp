#include<stdio.h>
int main()
{
    short t;long long k;
    scanf("%hd",&t);
    while(t--)
    {
        scanf("%lld",&k);
        printf("%lld\n",192+250*(k-1));
    }
    return 0;
}
