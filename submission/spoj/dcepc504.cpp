#include<bits/stdc++.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        unsigned long long N,K,l=1,k,i;
        scanf("%llu%llu",&N,&K);
        k=K-1;
        for(i=1;i<=N;i++)
        {
            if(k%2)
            {
                if(l) l=0;
                else l=1;
            }
            else
            {
                if(l) l=1;
                else l=0;
            }
            k/=2;
        }
        if(l) printf("Male\n");
        else printf("Female\n");
    }
    return 0;
}
