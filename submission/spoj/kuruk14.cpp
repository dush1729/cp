#include<stdio.h>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        short N,a[1000]={0},i,z,m=1;
        scanf("%hd",&N);
        for(i=0;i<N;i++)
        {
            scanf("%hd",&z);
            if(z>N-1) m=0;
            else a[z]++;
        }
        if(m)
        {
            if(N%2==0)
            {
                for(i=1;i<N/2;i++)
                {
                    if(a[i]+a[N-1-i]!=2) m=0;
                }
                if(a[N-1]!=2) m=0;
                if(m) printf("YES\n");
                else printf("NO\n");
            }
            else
            {
                for(i=1;i<N/2;i++)
                {
                    if(a[i]+a[N-1-i]!=2) m=0;
                }
                if(a[N-1]!=2) m=0;
                if(a[(N-1)/2]!=1) m=0;
                if(m) printf("YES\n");
                else printf("NO\n");
            }
        }
        else printf("NO\n");
    }
    return 0;
}
