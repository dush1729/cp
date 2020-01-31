#include<stdio.h>
#include<math.h>
int main()
{
    short a[2664]={0},i,j,b[2664]={0},T,n,z=0;
    for(i=2;i<=sqrt(2664);i++)
    {
        for(j=i*i;j<=2664;j+=i)
        {
            a[j]=1;
        }
    }
    j=0;
    for(i=2;i<=2664;i++) if(a[i]!=1) {b[j]=i;j++;}
    for(i=30;i<=2664;i++)
    {
        short i1=i,f=0;
        for(j=0;i1!=1;j++)
        {
            while(i1%b[j]==0)
            {
                i1/=b[j];
                if(i1%b[j]!=0) f++;
            }
        }
        if(f>2) {a[z]=i;z++;}
    }
    scanf("%hd",&T);
    while(T--)
    {
        scanf("%hd",&n);
        printf("%hd\n",a[n-1]);
    }
    return 0;
}
