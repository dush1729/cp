#include<bits/stdc++.h>
using namespace std;
int main ()
{
    while(1)
    {
        unsigned long long n;
        int i,a[35],num=1,den=1,l=0;
        scanf("%llu",&n);
        if(n==0) break;
        while(n!=1)
        {
            a[l++]=n%2;
            n/=2;
        }
        for(i=l-1;i>=0;i--)
        {
            if(a[i]==0) den+=num;
            else num+=den;
        }
        printf("%d/%d\n",num,den);
    }
    return 0;
}
