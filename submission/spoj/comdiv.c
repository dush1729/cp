#include<stdio.h>
#include<math.h>
int gcd(int a,int b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int A,B,g,i,z=0;
        scanf("%d%d",&A,&B);
        if(A>B)
        {
            g=gcd(A,B);
            for(i=1;i<=sqrt(g);i++)
                if(g%i==0) z+=2;
            if(sqrt(g)==(int)(sqrt(g))) printf("%d\n",--z);
            else printf("%d\n",z);
        }
        else
        {
            g=gcd(B,A);
            for(i=1;i<=sqrt(g);i++)
                if(g%i==0) z+=2;
            if(sqrt(g)==(int)(sqrt(g))) printf("%d\n",--z);
            else printf("%d\n",z);
        }
    }
    return 0;
}

