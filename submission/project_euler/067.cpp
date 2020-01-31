#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,i,j,a[N][N];
long long dp[N][N];
int main()
{
    freopen("i.txt","r",stdin);
    for(i=0;i<N;i++) for(j=0;j<=i;j++) scanf("%d",&a[i][j]);

    dp[0][0]=a[0][0];
    for(i=1;i<N;i++)
    {
        dp[i][0]=a[i][0]+dp[i-1][0];
        for(j=1;j<=i;j++) dp[i][j]=a[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
    }

    cout<<*max_element(dp[N-1],dp[N-1]+N);
}
