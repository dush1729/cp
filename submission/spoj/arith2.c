#include<stdio.h>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        int a,c;unsigned long long m;char b;
        scanf("%d",&a);
        m=a;
        while(b!='=')
        {
            scanf(" %c",&b);
            if(b=='=') break;
            scanf("%d",&c);
            if(b=='+') m=m+c;
            else if(b=='-') m=m-c;
            else if(b=='*') m=m*c;
            else if(b=='/') m=m/c;
        }
        b=90;
        printf("%llu\n",m);
    }
    return 0;
}
