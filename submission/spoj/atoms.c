#include<stdio.h>
#include<math.h>
int main()
{
    short P;long long N,K,M;float t;
    scanf("%d", &P);
    while(P--)
    {
        scanf("%lld %lld %lld", &N, &K, &M);
        t=log(M/N) / log(K);
        if(N>M) printf("0\n");
        else printf("%d\n", (int) t);
    }
    return 0;
}
