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
    scanf("%d",&T);
    while(T--)
    {
        int N,a[100002]={},i;
        long long b[100006]={};
        N=fast_input();
        for(i=0;i<N;i++) scanf("%d",&a[i]);
        for(i=N-1;i>=0;i--) b[i]=max(a[i]+b[i+2],max(a[i]+a[i+1]+b[i+4],a[i]+a[i+1]+a[i+2]+b[i+6]));
        printf("%lld\n",b[0]);
    }
    return 0;
}
