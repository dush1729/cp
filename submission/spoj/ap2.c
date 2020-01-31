#include<stdio.h>
int main()
{
 unsigned long long int a,b,d,S,t,c,n;
 scanf("%llu", &t);
 while(t--)
 {
     scanf("%llu %llu %llu", &a, &b, &S);
     n=(2*S)/(a+b);
     d=(b-a)/(n-5);
     printf("%llu\n", n);
     for(c=0;c<=n-1;c++)
        printf("%llu ", a+(c-2)*d);
    printf("\n");
 }
}




