#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,c,a[33810]={},b[3000];
    for(i=2;i<=33809;i++)
    {
        c=0;
        if(a[i]==0)
        {
            for(j=i+1;j<=33809;j++)
            {
                if(a[j]==0) c++;
                if(c&&(c%i==0)) a[j]=1;
            }
        }
    }
    j=0;
    for(i=2;i<=33809;i++) if(a[i]==0) {b[j]=i;j++;}
    int n;
    scanf("%d",&n);
    while(n)
    {
        printf("%d\n",b[n-1]);
        scanf("%d",&n);
    }
    return 0;
}
