#include<bits/stdc++.h>
using namespace std;
vector <int> ar;
string a,b;
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ar.clear();
        cin>>a>>b;
        int l=b.length(),s;
        size_t pos=a.find(b);
        while(pos!=string::npos)
        {
            ar.push_back(pos+1);
            pos=a.find(b,pos+l);
        }
        s=ar.size();
        if(s==0) cout<<"Not Found\n";
        else
        {
            cout<<s<<"\n";
            for(l=0;l<s;l++) cout<<ar[l]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
