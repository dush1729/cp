#include<bits/stdc++.h>
using namespace std;
pair <int,int> a[100000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,x,y,c=1,last;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            a[i]=make_pair(y,x);
        }
        sort(a,a+n);
        //first -> y
        //second -> x
        last=a[0].first;
        for(i=1;i<n;i++)
        {
            if(a[i].second>=last)
            {
                c++;
                last=a[i].first;
            }
        }
        printf("%d\n",c);
    }
    return 0;
}
