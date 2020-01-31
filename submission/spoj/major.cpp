#include<stdio.h>
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        short z[100000],y[200]={0},m=0,o;int i,n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%hd",&z[i]);
            if(z[i]<0) z[i]+=1000;
            y[z[i]]++;
            if(y[z[i]]>n/2) {m=1;o=z[i];}
        }
        if(m) printf("YES %hd\n",o);
        else printf("NO\n");
    }
}
