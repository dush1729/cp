#include<bits/stdc++.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,i,ans;
        double a[1000],m=-1,an;//m -> maximum
        char s[50];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            fflush(stdin);
            scanf("%s %lf",s,&a[i]);
        }
        std::sort(a,a+n);
        for(i=0;i<n-1;i++)
        {
            an=a[i+1]-a[i];
            if(m<an) m=an;
        }
        an=360-a[n-1]+a[0];
        if(m<an) m=an;
        ans=ceil(12*(360-m));
        printf("%d\n",ans);
    }
    return 0;
}
