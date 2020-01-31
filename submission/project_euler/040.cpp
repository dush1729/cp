#include "bits/stdc++.h"
using namespace std;

int f(int pos)
{
    int len=1,p=9,start=1,total=0;
    while(total+len*p<pos)
    {
        total+=len*p;
        len++;
        p*=10;
        start*=10;
    }

    int number=start+(pos-total-1)/len;
    return to_string(number)[(pos-total-1)%len]-'0';
}

int main()
{
    int ans=1;
    for(int i=1;i<=1e6;i*=10) ans*=f(i);
    cout<<ans;
}