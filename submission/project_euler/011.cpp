#include<bits/stdc++.h>
using namespace std;
const int n=20;
int i,j,k,cnt,a[n][n],ans,p;
int main()
{
    freopen("i.txt","r",stdin);
    for(i=0;i<n;i++) for(j=0;j<n;j++) scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=i,cnt=0,p=1;k<n and cnt<4;k++,cnt++) p*=a[i][k];
            ans=max(ans,p);

            for(k=i,cnt=0,p=1;k<n and cnt<4;k++,cnt++) p*=a[k][j];
            ans=max(ans,p);

            for(cnt=0,p=1;i+cnt<n and j+cnt<n and cnt<4;cnt++)
                p*=a[i+cnt][j+cnt];
            ans=max(ans,p);

            for(cnt=0,p=1;i+cnt<n and j-cnt>=0 and cnt<4;cnt++)
                p*=a[i+cnt][j-cnt];
            ans=max(ans,p);
        }
    }
    cout<<ans;
}
