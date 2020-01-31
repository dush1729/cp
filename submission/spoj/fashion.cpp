#include<stdio.h>
#include<algorithm>
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        short N,i,j,m[1000],w[1000],temp;int s=0;
        scanf("%hd",&N);
        for(i=0;i<N;i++)
            scanf("%hd",&m[i]);
        std::sort(m,m+N);
        for(i=0;i<N;i++)
            scanf("%hd",&w[i]);
        std::sort(w,w+N);
        for(i=0;i<N;i++)
            s=s+m[i]*w[i];
        printf("%d\n",s);
    }
}
