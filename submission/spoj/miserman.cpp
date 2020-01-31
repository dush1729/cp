#include<stdio.h>
int mi(int a,int b,int c)
{
    if((a<=b)&&(a<=c)) return a;
    else if((b<=a)&&(b<=c)) return b;
    else return c;
}
int main()
{
    int N,M,i,j,a,b[100],c[100],m=2000000000;
    scanf("%d%d",&N,&M);
    for(i=0;i<M;i++)
    {
        scanf("%d",&a);
        b[i]=c[i]=a;
    }
    for(i=1;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            scanf("%d",&a);
            if(j==0) c[0]=a+mi(b[0],b[1],2000000000);
            else if(j==M-1) c[M-1]=a+mi(b[M-1],b[M-2],2000000000);
            else c[j]=a+mi(b[j-1],b[j],b[j+1]);
        }
        for(j=0;j<M;j++) b[j]=c[j];
    }
    for(i=0;i<M;i++) if(m>c[i]) m=c[i];
    printf("%d\n",m);
    return 0;
}
