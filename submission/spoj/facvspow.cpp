#include<stdio.h>
#include<math.h>
int a,d,f;
int ans(int b,int c)
{
    double e;
    if(b<c)
    {
        d=(b+c)/2;
        e=(0.5*logl(2*M_PI*d)+d*1.0*logl(d/M_E))/logl(a);
        if(e>d)
        {
            c=f=d;
            ans(b,c);
        }
        else
        {
            b=d+1;
            ans(b,c);
        }
    }
    else return f;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int z,r;
        scanf("%d",&a);
        r=a*M_E;
        z=ans(2*a,r);
        printf("%d\n",z);
    }
    return 0;
}
