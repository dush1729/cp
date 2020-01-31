#include<stdio.h>
int main()
{
 short int N,a,b;int c=0;
 scanf("%d", &N);
 for(a=1;a<=N;a++)
 {
     for(b=a;b<=N;b++)
        if(a*b<=N)c++;
 }
 printf("%d", c);
 return 0;
}

