#include<bits/stdc++.h>
using namespace std;
vector<bool> a(10000001,false);
int b[10000002],i,j;
int main()
{
    for(i=2;i<=3163;i++) if(a[i]==false) for(j=i*i;j<=10000000;j+=i) a[j]=true;
    j=0;
    for(i=2;i<=10000000;i++) if(a[i]==false) b[i]=++j; else b[i]=j;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,c=0;
        scanf("%d",&n);
        printf("%d\n",b[n]-b[n/2]);
    }
    return 0;
}
