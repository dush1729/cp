#include<stdio.h>
int max(int a,int b,int c)
{
    if((a>=b)&&(a>=c)) return a;
    else if((b>=a)&&(b>=c)) return b;
    else return c;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int h,w,i,j,a,b[100],c[100],m=-1;
        scanf("%d%d",&h,&w);
        for(i=0;i<w;i++)
        {
            scanf("%d",&a);
            b[i]=a;
            c[i]=a;
        }
        for(i=1;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                scanf("%d",&a);
                if(j==0) c[0]=a+max(b[0],b[1],-1);
                else if(j==w-1) c[w-1]=a+max(b[w-1],b[w-2],-1);
                else c[j]=a+max(b[j-1],b[j],b[j+1]);
            }
            for(j=0;j<w;j++) b[j]=c[j];
        }
        for(i=0;i<w;i++) if(m<c[i]) m=b[i];
        printf("%d\n",m);
    }
    return 0;
}
