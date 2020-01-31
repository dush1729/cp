#include<stdio.h>
main()
{
 int T,N,a,b,s=0;
 scanf("%d", &T);
 while(T--)
 {
     scanf("%d", &N);
     for(a=5;a<=N;a=a*5)
     {
         b=N/a;
         s=s+b;
     }
     printf("%d\n", s);
     s=0;
 }
}



