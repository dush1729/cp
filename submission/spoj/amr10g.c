#include<stdio.h>
#include<algorithm>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        short N,K,i,j;int temp,m=1000000001;
        scanf("%hd%hd",&N,&K);
        int h[N];
        for(i=0;i<N;i++)
            scanf("%d",&h[i]);
        std::sort(h,h+N);
        for(i=0;i<=N-K;i++)
            if(h[i+K-1]-h[i]<m) m=h[i+K-1]-h[i];
        printf("%d\n",m);
    }
}
