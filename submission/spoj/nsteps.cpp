#include<stdio.h>
int main()
{
 int N,x,y;
 scanf("%d", &N);
 while(N!=0)
 {
     scanf("%d%d",&x,&y);
     if(y==x)
     {
         if(x%2==0) printf("%d\n", x*2);
         else printf("%d\n", x+y-1);
     }
     else if(y==x-2)
     {
         if(x%2==0) printf("%d\n", x+y);
         else printf("%d\n", x+y-1);
     }
     else printf("No Number\n");
     N=N-1;
 }
 return 0;
}





