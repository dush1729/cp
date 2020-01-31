#include<stdio.h>
#include<math.h>
int main()
{
    int n,b,bn,m,p,d;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1) printf("0 0\n");
        else
        {
            b=(3+sqrt(12*n-3))/6;
            if(sqrt(12*n-3)!=(int)sqrt(12*n-3)) b++;
            bn=3*b*b-3*b+1;
            d=bn-n;
            m=d%(b-1);
            p=d/(b-1);
            b--;
            if(p==0) printf("%d %d\n",b,-m);
            else if(p==1) printf("%d %d\n",b-m,-b);
            else if(p==2) printf("%d %d\n",-m,-b+m);
            else if(p==3) printf("%d %d\n",-b,m);
            else if(p==4) printf("%d %d\n",-b+m,b);
            else if(p==5) printf("%d %d\n",m,b-m);
        }
    }
    return 0;
}
