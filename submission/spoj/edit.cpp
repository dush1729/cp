#include<bits/stdc++.h>
using namespace std;

char a[1009];
int main()
{
    while(scanf(" %s",a)!=EOF)
    {
        int i,len=strlen(a),ans=INT_MAX,cnt=0;
        for(i=0;i<len;i++)
        {
            if(i%2==0)
            {
                if(a[i]>='a' and a[i]<='z') cnt++;
            }
            else
            {
                if(a[i]>='A' and a[i]<='Z') cnt++;
            }
        }
        ans=min(ans,cnt);
        cnt=0;
        for(i=0;i<len;i++)
        {
            if(i%2==1)
            {
                if(a[i]>='a' and a[i]<='z') cnt++;
            }
            else
            {
                if(a[i]>='A' and a[i]<='Z') cnt++;
            }
        }
        ans=min(ans,cnt);
        printf("%d\n",ans);
    }
    return 0;
}
