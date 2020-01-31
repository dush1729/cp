#include<bits/stdc++.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N1,N2,i,j,a[1000],b[1000],l=0,m=1000000000;
        scanf("%d",&N1);
        for(i=0;i<N1;i++) scanf("%d",&a[i]);
        scanf("%d",&N2);
        for(i=0;i<N2;i++) scanf("%d",&b[i]);
        std::sort(a,a+N1);
        std::sort(b,b+N2);
        for(i=0;i<N1;i++)
        {
            for(j=0;j<N2;j++) if(m>abs(a[i]-b[j])) m=abs(a[i]-b[j]);
            //if(j==N2) j=N2-1;
            if(m==0) break;
            //printf("%d\n",m);
        }
        printf("%d\n",m);
    }
    return 0;
}
