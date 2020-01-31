#include<bits/stdc++.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n<=2) printf("0\n");
        else printf("%d\n",n-2);
    }
    return 0;
}
