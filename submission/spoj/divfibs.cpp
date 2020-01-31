#include<bits/stdc++.h>
using namespace std;
long long a[100001];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long i,L,R,M,pos=-1,ans;
        a[1]=a[2]=1;
        for(i=2;i<=86;i++) a[i]=a[i-1]+a[i-2]; //at 87 it exceeds
        scanf("%lld%lld%lld",&L,&R,&M);
        if(M==1) printf("%lld\n",R-L+1);
        else
        {
            for(i=2;i<=R;i++)
            {
                a[i]=(a[i-1]+a[i-2])%M;
                if(a[i]==0) {pos=i;break;}
            }
            if(pos==-1) ans=0;
            else ans=(R/(pos))-((L-1)/(pos));
            printf("%lld\n",ans);
        }
    }
    return 0;
}
