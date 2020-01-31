#include<stdio.h>
#include<math.h>
int main()
{
    short a[31624]={},b[31624]={},j,l=0,n;int i,x,y;
    for(i=2;i<=sqrt(31623);i++)
    {
        for(j=i*i;j<=31623;j+=i) a[j]=1;
    }
    j=0;
    for(i=2;i<=31623;i++) if(a[i]!=1) {b[j]=i;j++;}
    scanf("%d%d%hd",&x,&y,&n);
    for(i=x;i<=y;i++)
    {
        int z=i;short c,d=1;
        for(j=0;z!=1;j++)
        {
            c=0;
            if(j<3401)
            {
                while(z%b[j]==0)
                {
                    z/=b[j];
                    c++;
                }
                d*=(c+1);
            }
            else
            {
                d*=2;
                z=1;
            }
        }
        if(d==n) l++;
    }
    printf("%hd\n",l);
    return 0;
}
