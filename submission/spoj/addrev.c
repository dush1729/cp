#include<stdio.h>
int main()
{
    short N;int a,b,c=0;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d%d",&a,&b);
        while(a)
        {
            c=10*c+(a%10);
            a/=10;
        }
        while(b)
        {
            a=10*a+(b%10);
            b/=10;
        }
        b=a+c;
        a=0;
        while(b)
        {
            a=10*a+(b%10);
            b/=10;
        }
        printf("%d\n",a);
        c=0;
    }
    return 0;
}
