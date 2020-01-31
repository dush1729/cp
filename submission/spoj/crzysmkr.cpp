#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define lld I64d
unsigned long long modulo(unsigned long long a,unsigned long long b)
{
    unsigned long long x=1,y=a;
    while(b>0)
    {
        if(b%2==1) x=(x*y)%11;
        y=(y*y)%11;
        b/=2;
    }
    return x%11;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long N,m,s;
        scanf("%lld",&N);
        s=(modulo(34,N)+30*N+32)%11;
        for(m=0;m<11;m++)
        {
            if((s+m)%11==0) {printf("%lld\n",m);break;}
        }
    }
    return 0;
}
