#include<iostream>
using namespace std;
int main()
{
    char b;
    short t,h1,m1,h2,m2,a,c=0;
    cin>>t;
    while(t--)
    {
        cin>>h1>>b>>m1>>h2>>b>>m2;
        for(a=h1;a<=h2;a++)
        {
            if( (a<h2) &&  (a!=11) && (a!=23) ) c++;
            else
                if( (a!=11) && (a!=23) && ( m2 > ( 60* float((a%12) /11.0) ) ) ) c++;
            else
                if( ( (a==24) || (a==12) ) && (m2==0) ) c++;
        }
        if( ( (h1==0) || ( h1==12) ) && (m1==0) ) c--;
        cout<<c<<"\n";
        c=0;
    }
}

