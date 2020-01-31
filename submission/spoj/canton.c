#include<stdio.h>
int main()
{
    short t;long a,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        for(a=1;(a*(a+1)/2) < n;a++) ;
        if(a%2)
        {
            printf("TERM %ld IS %ld/%ld\n",n,a*(a+1)/2-n+1,a+n-a*(a+1)/2);
        }
        else
        {
            printf("TERM %ld IS %ld/%ld\n",n,a+n-a*(a+1)/2,a*(a+1)/2-n+1);
        }
    }
    return 0;
}
