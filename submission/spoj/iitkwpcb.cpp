#include<stdio.h>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        if((n==1)||(n==2)) printf("1\n");
        else if(n%2) printf("%lld\n",n/2);
        else if(n%4) printf("%lld\n",(n/2)-2);
        else printf("%lld\n",(n/2)-1);
    }
    return 0;
}
