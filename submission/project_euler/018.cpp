#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,i,j,a[N][N],ans;
int f(int i,int j,int s)
{
    if(i==15) return s;
    return max(f(i+1,j,s+a[i][j]),f(i+1,j+1,s+a[i][j]));
}
int main()
{
    freopen("i.txt","r",stdin);
    for(i=0;i<N;i++) for(j=0;j<=i;j++) scanf("%d",&a[i][j]);

    cout<<f(0,0,0);
}
