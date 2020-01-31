#include<stdio.h>
main()
{
    short int T;long long int N;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld", &N);
        printf("%lld\n", (N*(3*N+1)/2)%1000007);
    }
}


