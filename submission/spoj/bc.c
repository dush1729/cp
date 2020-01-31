#include<stdio.h>
#include<math.h>
int main()
{
    short T,N,M,K,a,b=0;long long c;
    scanf("%hd",&T);
    for(a=1;a<=T;a++)
    {
        scanf("%hd%hd%hd",&N,&M,&K);
        c=(long long)N*M*K;
        if(!(N&(N-1))) b=b+log2(N); else b=b+log2(N)+1;
        if(!(M&(M-1))) b=b+log2(M); else b=b+log2(M)+1;
        if(!(K&(K-1))) b=b+log2(K); else b=b+log2(K)+1;
        printf("Case #%hd: %lld %hd\n",a,c-1,b);
        b=0;
    }
    return 0;
}
