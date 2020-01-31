#include<bits/stdc++.h>
unsigned a[10000001]={},i,j;
unsigned long long b[10000001]={};
unsigned long long fast_input() {
  char c;
  do { c = getchar(); } while( c != '-' && !isdigit(c) );
  bool neg = (c == '-');
  unsigned long long result = neg ? 0 : c - '0';
  while( isdigit(c = getchar()) )
    result = 10 * result + (c - '0');
  return neg ? -result : result;
}
int main()
{
    a[1]=1;
    for(i=2;i<=10000000;i+=2) a[i]=2;
    for(i=3;i<=3163;i+=2) if(a[i]==0) for(j=i*i;j<=10000000;j+=i) if(a[j]==0) a[j]=i;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        unsigned long long phi,n,lastdiv,number,root;
        n=fast_input();
        if(b[n]) printf("%llu\n",b[n]);
        else
        {
            if(a[n])
            {
                lastdiv=0;
                number=phi=n;
                while(number!=1)
                {
                    if(a[number]==0)
                    {
                        if(lastdiv!=number) phi=phi*(number-1)/number;
                        number=1;
                    }
                    else
                    {
                        if(lastdiv!=a[number]) phi=phi*(a[number]-1)/a[number];
                        lastdiv=a[number];
                        number/=a[number];
                    }
                }
            }
            else phi=n-1;
            printf("%llu\n",phi);
            b[n]=phi;
        }
    }
    return 0;
}
