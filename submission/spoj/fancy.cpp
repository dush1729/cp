#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char a[31];
        scanf(" %s",a);
        int i,l,c=1;
        unsigned long long p=1;
        l=a[0];
        for(i=1;a[i]!='\0';i++)
        {
            if(a[i]==l) c++;
            else
            {
                p*=1<<(c-1);
                c=1;
                l=a[i];
            }
        }
        p*=1<<(c-1);
        printf("%llu\n",p);
    }
    return 0;
}
