#include<bits/stdc++.h>
using namespace std;
const int N=16;
int t,n,i,ans[N];
int main()
{
    for(n=1;n<=14;n++)
    {
        map <pair<int,int>,int> m[N];
        map <pair<int,int>,int>::iterator j;
        m[0][make_pair(0,0)]=1;
        for(i=1;i<=n;i++)
        {
            for(j=m[i-1].begin();j!=m[i-1].end();j++)
            {
                int x=(*j).first.first, y=(*j).first.second, ways=(*j).second;
                m[i][make_pair(x-1,y)]+=ways;
                m[i][make_pair(x+1,y)]+=ways;
                m[i][make_pair(x,y+1)]+=ways;
                m[i][make_pair(x,y-1)]+=ways;
                m[i][make_pair(x+1,y-1)]+=ways;
                m[i][make_pair(x-1,y+1)]+=ways;
            }
        }
        ans[n]=m[n][make_pair(0,0)];
    }

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
}
