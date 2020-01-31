#include<bits/stdc++.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        unsigned long long N,P,a=1,n;
        scanf("%llu%llu",&N,&P);
        n=N;
        while(N)
        {
            a=a*(1+(N%P));
            N/=P;
        }
        printf("%llu\n",n+1-a);
    }
    return 0;
}
