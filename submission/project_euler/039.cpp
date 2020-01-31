#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int a,b,c,f[N+1],mx,v;
int main()
{
    for(a=1;a<=N;a++)
    {
        for(b=1;b<=N;b++)
        {
            c=sqrt(a*a+b*b);
            if(c!=sqrt(a*a+b*b)) continue;
            if(a+b+c>N) break;

            f[a+b+c]++;
            if(mx<f[a+b+c]) mx=f[a+b+c], v=a+b+c;
        }
    }

    cout<<v;
}
