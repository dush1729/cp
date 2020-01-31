#include<bits/stdc++.h>
using namespace std;
int fast_input() {
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
    int T;
    T=fast_input();
    while(T--)
    {
        int N,i,a,b;
        long long s=0;
        N=fast_input();
        a=fast_input();
        for(i=1;i<N;i++)
        {
            b=fast_input();
            s+=b*i-a*(N-i);
            a=b;
        }
        printf("%lld\n",s);
    }
    return 0;
}
