#include<bits/stdc++.h>
int main()
{
    int T,n,i,j,k,a[12][12]={},b[12]={0,1};
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        if(b[n]) printf("%d\n",b[n]);
        else
        {
            for(i=2;i<=n;i++)
            {
                if(b[i]) continue;
                for(j=1;j<=i;j++)
                {
                    if((j==1)||(j==i)) a[i][j]=1;
                    else a[i][j]=j*a[i-1][j]+a[i-1][j-1];
                    b[i]+=a[i][j];
                }
            }
            printf("%d\n",b[n]);
        }
    }
    return 0;
}
