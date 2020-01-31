#include<stdio.h>
int main()
{
    short t;long long N,a,b=1;
    scanf("%hd",&t);
    while(t--)
    {
        scanf("%lld",&N);
        for(a=0;b<N;a++)
        {
            b=b+a;
        }
        a--;
        if(N==1) printf("0\n");
        else printf("%lld\n",a);
        b=1;
    }
}
