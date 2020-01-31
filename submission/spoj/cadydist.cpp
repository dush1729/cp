#include<stdio.h>
#include<algorithm>
int main()
{
    unsigned N;
    scanf("%u",&N);
    while(N)
    {
        unsigned i,j,C[100000],P[100000];unsigned long long s=0;
        for(i=0;i<N;i++) scanf("%u",&C[i]);
        for(i=0;i<N;i++) scanf("%u",&P[i]);
        std::sort(C,C+N);
        std::sort(P,P+N);
        j=N-1;
        for(i=0;i<N;i++)
        {
            s+=(unsigned long long)C[i]*P[j];
            j--;
        }
        printf("%llu\n",s);
        scanf("%u",&N);
    }
    return 0;
}
