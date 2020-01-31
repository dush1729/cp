#include<bits/stdc++.h>
using namespace std;
const int N=10;
int i,n=1e6,a[N],cnt=1;
int main()
{
    for(i=0;i<N;i++) a[i]=i;

    while(cnt++<n) next_permutation(a,a+N);

    for(auto i:a) cout<<i;
}
