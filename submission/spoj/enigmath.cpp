#include<stdio.h>
long gcd(long,long);
main()
{
   short T;
   scanf("%hd",&T);
   while(T--)
   {
       long A,B,l,m=1;
       scanf("%ld%ld",&A,&B);
       if(A>=B)
       {
            m=gcd(A,B);
            printf("%ld %ld\n", B/m, A/m);
       }
       else
       {
            m=gcd(B,A);
            printf("%ld %ld\n", B/m, A/m);
       }
   }
}
long gcd(long x,long y)
{
    if(x%y==0) return y;
    else return gcd(y,x%y);
}

