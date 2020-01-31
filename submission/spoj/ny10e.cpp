#include<stdio.h>
int main()
{
    int P;
    scanf("%d",&P);
    while(P--)
    {
        unsigned long long a,N,i,j,d[10]={1,2,3,4,5,6,7,8,9,10};
        scanf("%llu%llu",&a,&N);
        for(i=2;i<=N;i++)
        {
            for(j=0;j<10;j++)
            {
                if(j>0) d[j]=d[j]+d[j-1];
            }
        }
        printf("%llu %llu\n",a,d[9]);
    }
    return 0;
}
