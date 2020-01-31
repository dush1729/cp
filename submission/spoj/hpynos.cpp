#include<bits/stdc++.h>
unsigned long long next_int()
{
    char c;
    do { c = getchar(); } while( c != '-' && !isdigit(c) );
    bool neg = (c == '-');
    int result = neg ? 0 : c - '0';
    while( isdigit(c = getchar()) )
        result = 10 * result + (c - '0');
    return neg ? -result : result;
}
int main()
{
    int N,a[811]={},cou=0,n1,n2;
    N=next_int();
    while((a[N]!=1)&&(N!=1))
    {
        if(N<811) a[N]=1;
        n1=N;
        n2=0;
        while(n1)
        {
            n2+=(n1%10)*(n1%10);
            n1/=10;
        }
        N=n2;
        cou++;
    }
    if(N==1) printf("%d\n",cou);
    else printf("-1\n");
    return 0;
}
