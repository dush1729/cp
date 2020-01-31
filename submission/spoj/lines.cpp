#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1)
    {
        int N,x[1000],y[1000],i,j;
        double r;
        set <double> a;
        scanf("%d",&N);
        if(N==0) break;
        for(i=0;i<N;i++) scanf("%d%d",&x[i],&y[i]);
        for(i=0;i<N-1;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(x[j]==x[i]) a.insert(100000.0);
                else
                {
                    r=1.0*(y[j]-y[i])/(x[j]-x[i]);
                    a.insert(r);
                }
            }
        }
        printf("%d\n",a.size());
    }
    return 0;
}
