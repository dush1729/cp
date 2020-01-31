#include<stdio.h>
int main()
{
    short N,a[10000],b;int c=0,d=0;
    scanf("%hd",&N);
    while(N!=-1)
    {
        for(b=0;b<N;b++)
        {
            scanf("%hd",&a[b]);
            c+=a[b];
        }
        if(c%N) printf("-1\n");
        else
        {
            c=c/N;
            for(b=0;b<N;b++)
                if((c-a[b])<0) d=d+c-a[b];
            printf("%d\n",-d);
        }
        c=0;d=0;
        scanf("%hd",&N);
    }
    return 0;
}
