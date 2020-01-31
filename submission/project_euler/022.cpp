#include<bits/stdc++.h>
using namespace std;
string a;
vector <string> b;
long long i,ans;
int main()
{
    freopen("input.txt","r",stdin);

    cin>>a;
    a=a.substr(1);
    while(1)
    {
        int idx=a.find('"');
        b.push_back(a.substr(0,idx));
        if(idx+2<a.size()) a=a.substr(idx+3);
        else break;
    }

    sort(b.begin(),b.end());

    for(i=0;i<b.size();i++)
        for(auto j:b[i])
            ans+=(i+1)*(j-'A'+1);

    cout<<ans;
}
