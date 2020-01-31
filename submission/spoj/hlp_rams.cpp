#include<stdio.h>
#include<math.h>
int main()
{
    unsigned t;
    scanf("%u",&t);
    while(t--)
    {
        unsigned c=0;unsigned long long n,a;
        scanf("%llu",&n);
        if(n)
        {
            a=n;
            while(n!=1)
            {
                if(n%2) c++;
                n/=2;
            }
            c++;
            c=1<<c;
            printf("%llu %u\n",a+1-c,c);
        }
        else printf("0 1\n");
    }
}
