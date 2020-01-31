#include<bits/stdc++.h>
using namespace std;

const int N=2009;

int n,a[N],i,j,k,ans;
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        ans=0;
        for(i=n-1;i>1;i--)
        {
            j=0;
            k=i-1;
            while(j<k)
            {
                while(j<k and a[j]+a[k]>=a[i]) k--;
                ans+=k-j;
                j++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
