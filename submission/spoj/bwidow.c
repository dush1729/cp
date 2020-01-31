#include<stdio.h>
int main()
{
    short T,N,a,b=-1;int r,R[1000],m1=1,m2=1;
    scanf("%hd",&T);
    while(T--)
    {
        scanf("%hd",&N);
        for(a=0;a<N;a++)
        {
            scanf("%d%d",&r,&R[a]);
            if(m1<r) {m1=r;b=a;}
        }
        for(a=0;a<N;a++)
        {
            if(b!=a)
                if(m2<R[a]) m2=R[a];
        }
        if(m1>=m2) printf("%hd\n",b+1);
        else printf("-1\n");
        b=-1;m1=1;m2=1;
    }
    return 0;
}

