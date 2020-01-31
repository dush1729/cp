#include<bits/stdc++.h>
using namespace std;
vector <bool> a(1000000,false);
int main()
{
    int i,j,s;
    for(i=1;i<1000000;i++)
    {
        j=s=i;
        while(j)
        {
            s+=j%10;
            j/=10;
        }
        for(;(s<1000000)&&(a[s]!=true);)
        {
            a[s]=true;
            j=s;
            while(j)
            {
                s+=j%10;
                j/=10;
            }
        }
    }
    for(i=1;i<1000000;i++) if(a[i]==false) printf("%d\n",i);
    return 0;
}
