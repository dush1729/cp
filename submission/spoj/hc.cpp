#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        char a[4];
        int i,c=0;
        for(i=0;i<N;i++)
        {
            scanf(" %s",a);
            if(a[0]=='h') c++;
        }
        if(N%2==0)
        {
            if(c%2==0) printf("hhb\n");
            else printf("lxh\n");
        }
        else
        {
            if(c%2==0) printf("lxh\n");
            else printf("hhb\n");
        }
    }
    return 0;
}
