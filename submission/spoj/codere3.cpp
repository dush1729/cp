#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int t,n,i,j,a[N],in[N],de[N],ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            in[i]=de[i]=1;
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(a[j]<a[i]) in[i]=max(in[i],in[j]+1);
            }
        }
        for(i=n-2;i>=0;i--)
        {
            for(j=n-1;j>i;j--)
            {
                if(a[j]<a[i]) de[i]=max(de[i],de[j]+1);
            }
        }
        ans=1;
        for(i=0;i<n;i++)
        {
            ans=max(ans,in[i]+de[i]-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
