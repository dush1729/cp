#include<bits/stdc++.h>
using namespace std;
const int N=2e4+20,L=30;
int t,n,k,i,j,x,BIT[L][N],p;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            for(j=0;j<L;j++,x>>=1) BIT[j][i]=x&1;
        }

        for(i=0;i<L;i++)
        {
            queue <pair<int,int>> q;
            for(j=0;j<n;j++)
                if(BIT[i][j]==0) q.push({j,0});

            while(!q.empty() and q.front().second<k)
            {
                int j=q.front().first, l=q.front().second+1;
                q.pop();

                if(BIT[i][(j-1+n)%n])
                {
                    q.push({(j-1+n)%n,l});
                    BIT[i][(j-1+n)%n]=0;
                }

                if(BIT[i][(j+1+n)%n])
                {
                    q.push({(j+1+n)%n,l});
                    BIT[i][(j+1+n)%n]=0;
                }
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0,x=0,p=1;j<L;j++,p<<=1) x+=p*BIT[j][i];
            printf("%d ",x);
        }
        printf("\n");
    }
}
