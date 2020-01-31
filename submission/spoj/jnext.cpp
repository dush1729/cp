#include<bits/stdc++.h>
int a[1000000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,p,ele,i;
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=n-1;i&&(a[i-1]>=a[i]);i--);
        if(i)
        {
            std::next_permutation(a,a+n);
            for(i=0;i<n;i++) printf("%d",a[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}
