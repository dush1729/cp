#include<stdio.h>
int main()
{
    short t;int n,a,b=0,c;
    scanf("%hd",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(c=0;c<n;c++)
        {
            scanf("%d",&a);
            b+=a;
        }
        b%=n;
        if(b) printf("%d\n",n-1);
        else printf("%d\n",n);
    }
}
