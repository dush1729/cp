#include<stdio.h>
#include<string.h>
int a[300000];
int main()
{
    long long N,M,i,s=0,l=0,m=-1;
    scanf("%lld%lld",&N,&M);
    for(i=0;i<N;i++) scanf("%d",&a[i]);
    for(i=0;i<N;i++)
    {
        s+=a[i];
        if(s==M)
        {
            m=s;
            break;
        }
        if(s>M)
        {
            while((s>M)&&(l<=i)) s-=a[l++];
            if(s==M)
            {
                m=s;
                break;
            }
        }
        if(m<s) m=s;
    }
    printf("%lld\n",m);
    return 0;
}
