#include<bits/stdc++.h>
int main()
{
    int n,i,s=3,a1=1,b1=1,c1=1,a2,b2,c2;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        a2=a1+b1;
        b2=a1+b1+c1;
        c2=b1+c1;
        s=a2+b2+c2;
        a1=a2;b1=b2;c1=c2;
    }
    printf("%d",s);
    return 0;
}
