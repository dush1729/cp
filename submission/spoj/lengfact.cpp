#include<stdio.h>
#include<math.h>
#define PI 3.1415926535897931L
#define E 2.7182818284590451L
int main()
{
    short t;
    long long n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        if(n<4) printf("1\n");
        else
            printf("%lld\n",(long long) (n*(log10(n)-log10(E))+0.5*log10(n)+0.5*log10(2*PI))+1);
    }
}








