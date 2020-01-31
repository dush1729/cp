#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int i,j,divi[N],z=0;
int main()
{
    for(i=1;i<N;i++)
        for(j=i;j<N;j+=i)
            divi[j]++;

    for(i=2;i<N;i++)
    {
        j=divi[i];
        bool possible=true;
        int cnt,tcnt=0;
        for(int k=2;j!=1;k++)
        {
            cnt=0;
            while(j%k==0)
            {
                cnt++;
                j/=k;
            }
            if(cnt>1)
            {
                possible=false;
                break;
            }
            if(cnt==1) tcnt++;
        }
        if(possible and tcnt==2)
        {
            z++;
            if(z%9==0) printf("%d\n",i);
        }
    }
}
