#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,i,a[10001],z=1;
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=1;i<n;i++)
        {
            if(a[i]>=a[i-1])
            {
                a[i]-=a[i-1];
                a[i-1]=0;
            }
            else
            {
                z=0;
                printf("NO\n");
                break;
            }
        }
        if(z==0) continue;
        for(i=0;i<n;i++) if(a[i]!=0) {z=0;printf("NO\n");break;}
        if(z) printf("YES\n");
    }
    return 0;
}
