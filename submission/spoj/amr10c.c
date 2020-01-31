#include<stdio.h>
#include<math.h>
int main()
{
    unsigned short a[1001]={},b[168]={},i,j;
    for(i=2;i<=sqrt(1000);i++)
    {
        if(!a[i])for(j=i*i;j<=1000;j+=i) a[j]=1;
    }
    j=0;
    for(i=2;i<=1000;i++) if(a[i]!=1) {b[j]=i;j++;}
    unsigned short T;
    scanf("%hd",&T);
    while(T--)
    {
        unsigned N;unsigned short p,ma=0;
        scanf("%u",&N);
        for(i=0;(N!=1)&&(i!=168);i++)
        {
            p=0;
            while(N%b[i]==0)
            {
                N/=b[i];
                p++;
            }
            if(ma<p) ma=p;
        }
        if((N!=1)&&(ma==0)) ma=1;
        printf("%hu\n",ma);
    }
    return 0;
}
