#include<bits/stdc++.h>
using namespace std;
long long n,i;
int main()
{
    while(1)
    {
        scanf("%lld",&n);
        if(n==0) break;

        map <long long,int> m;
        for(i=2;i*i<=n;i++)
            while(n%i==0) m[i]++, n/=i;
        if(n!=1) m[n]++;

        for(auto i:m) printf("%lld^%d ",i.first,i.second);
        printf("\n");
    }
}
