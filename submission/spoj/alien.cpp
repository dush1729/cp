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
        register int at,bt,a[100000],l=0,s=0,st=0,stmax=0,mp=1000000001,i;
        at=fast_input();
        bt=fast_input();
        for(i=0;i<at;i++) a[i]=fast_input();
        for(i=0;i<at;i++)
        {
            s+=a[i];
            if(s>bt)
            {
                st++;
                while((s>bt)&&(l<=i))
                {
                    s-=a[l++];
                    st--;
                }
                if((stmax==st)&&(mp>s)) mp=s;
            }
            else
            {
                st++;
                if(stmax<st)
                {
                    stmax=st;
                    mp=s;
                }
                else if((stmax==st)&&(mp>s)) mp=s;
            }
        }
        printf("%d %d\n",mp,stmax);
    }
    return 0;
}
