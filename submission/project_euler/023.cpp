#include<bits/stdc++.h>
using namespace std;
const int N=28124;
int n,i,j,d[N],s;
vector <int> a;
bool b[N];
int main()
{
    for(i=1;i<N;i++)
        for(j=2*i;j<N;j+=i)
            d[j]+=i;

    for(i=1;i<N;i++) if(d[i]>i) a.push_back(i);

    for(i=0;i<a.size();i++)
        for(j=i;j<a.size() and a[i]+a[j]<N;j++)
            b[a[i]+a[j]]=true;

    for(i=1;i<N;i++) if(!b[i]) s+=i;

    cout<<s;
}
