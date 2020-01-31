#include<bits/stdc++.h>
using namespace std;
const int N=1e7+20;
int t,n,i,j,p[N];
int main()
{
    for(i=4;i<N;i+=2) p[i]=2;
    for(i=3;i*i<N;i+=2)
    {
        if(!p[i])
            for(j=i*i;j<N;j+=i)
                if(!p[j]) p[j]=i;
        if(i%6==1) i+=2;
    }

    for(i=1;i<N;i++) if(!p[i]) p[i]=i;

    while(scanf("%d",&n)==1)
    {
        if(n!=1) printf("1 x ");
        else printf("1\n");
        while(n!=1)
        {
            if(n!=p[n]) printf("%d x ",p[n]);
            else printf("%d\n",p[n]);
            n/=p[n];
        }
    }
}
