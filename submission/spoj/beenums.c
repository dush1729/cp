#include<stdio.h>
int main()
{
   int N=0,a,b=0;
   while(N!=-1)
   {
       scanf("%d", &N);
       for(a=1;a<=N;a=a+(6*b))
       {
           if(a==N) printf("Y\n");
           else if(N < ( a + ( 6 * (b+1) ) ) ) {printf("N\n");break;}
           b++;
       }
       b=0;
   }
   return 0;
}





