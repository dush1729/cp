#include<stdio.h>
#include<algorithm>
int main()
{
    short T,t;
    scanf("%hd",&T);
    for(t=1;t<=T;t++)
    {
        short N,i,j,q=1,p;int H,M,S,a[20000],l,m;
        scanf("%hd",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d:%d:%d",&H,&M,&S);
            a[i]=3600*H+60*M+S;
        }
        scanf("%d",&l);
        std::sort(a,a+N);
        p=0;
        for(i=1;i<N;i++)
        {
            if(a[i]-a[p]+1>l) p++;
            else q++;
        }
        if(N) printf("Case %hd: %hd\n",t,q);
        else printf("Case %hd: 0\n",t);
    }
    return 0;
}
