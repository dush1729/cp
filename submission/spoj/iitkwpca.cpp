#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int T;
    scanf("%d",&T);
    cin.ignore();
    while(T--)
    {
        set <string> b;
        string a;
        getline(cin,a);
        int l=a.size(),i=0,j=0;
        string v;
        while(1)
        {
            while((i<l)&&(a[i]==' ')) i++;
            if(i==l) break;
            while((i<l)&&(a[i]!=' ')) {v+=a[i];i++;}
            b.insert(v);//cout<<v<<"\n";
            v.clear();
            if(i==l) break;
        }
        printf("%d\n",b.size());
    }
    return 0;
}
