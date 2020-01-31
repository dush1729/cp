#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;
int t,n,i,j,p[N];
vector <int> primes;
map <int,int> m;
long long num,den,ans;
void run(long long a,long long b)
{
    long long p=1;
    for(i=1;i<=b+1;i++) p*=a;
    
    num*=(p-1);
    den*=a-1;
}
int main()
{
    for(i=2;i*i<N;i++)
    {
        if(!p[i])
        {
            for(j=i*i;j<N;j+=i) if(!p[j]) p[j]=i;
        }
    }

    for(i=2;i<N;i++)
    {
        if(!p[i])
        {
            p[i]=i;
            primes.push_back(i);
        }
    }

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        m.clear();
        num=den=1;

        for(i=0;n>=N and i<primes.size();i++)
        {
            while(n%primes[i]==0) m[primes[i]]++, n/=primes[i];
        }
        if(n>N) m[n]++, n=1;
        while(n!=1) m[p[n]]++, n/=p[n];

        for(auto i:m) run(i.first,i.second);

        printf("%lld\n",num/den);
    }
}
