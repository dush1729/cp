#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char B[251];
        int a,i,ans=0;
        scanf("%d %s",&a,B);
        if(a==0) printf("%s\n",B);
        else
        {
            for(i=0;B[i]!='\0';i++) ans=(ans*10+(B[i]-'0'))%a;
            ans=gcd(ans,a);
            printf("%d\n",ans);
        }
    }
    return 0;
}
