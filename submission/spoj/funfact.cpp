#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846L
#define E 2.718281828459045L
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long x,lo=2,hi,mid,v,n;
        long double m;
        scanf("%lld",&x);
        hi=30000000000LL;
        while(lo<=hi)
        {
            mid=(lo+hi)/2;
            m=1.0L+((0.5L*log(2.0L*PI*mid)+mid*log(mid)-mid*log(E))/log(10));
            m=floor(m);
            if(m<=x)
            {
                v=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        printf("%lld\n",v);
    }
    return 0;
}
