#include<stdio.h>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        short n,k,i,z=0,nc=0;int a[100]={},s=0;
        scanf("%hd%hd",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==0) z++;
            else if(a[i]<0) nc++;
        }
        if((z==0)&&(nc==0))
        {
            if(k%2==1) s=-a[0];
            else s=a[0];
            for(i=1;i<n;i++) s+=a[i];
            printf("%d\n",s);
        }
        else if(z&&(nc==0))
        {
            for(i=z;i<n;i++) s+=a[i];
            printf("%d\n",s);
        }
        else if((n-nc==0)&&(z==0))
        {
            if(k<=n)
            {
                for(i=0;i<k;i++) s-=a[i];
                for(;i<n;i++) s+=a[i];
                printf("%d\n",s);
            }
            else
            {
                for(i=0;i<nc-1;i++) s-=a[i];
                if((k-n)%2)  s+=a[i];
                else s-=a[i];
                printf("%d\n",s);
            }
        }
        else if((n-nc-z==0)&&z)
        {
            if(k<=nc)
            {
                for(i=0;i<k;i++) s-=a[i];
                for(;i<n;i++) s+=a[i];
                printf("%d\n",s);
            }
            else
            {
                for(i=0;i<nc;i++) s-=a[i];
                printf("%d\n",s);
            }
        }
        else if((n-nc-z>0)&&z&&nc)
        {
            if(k<=nc)
            {
                for(i=0;i<k;i++) s-=a[i];
                for(;i<n;i++) s+=a[i];
                printf("%d\n",s);
            }
            else
            {
                for(i=0;i<nc;i++) s-=a[i];
                for(;i<n;i++) s+=a[i];
                printf("%d\n",s);
            }
        }
        else
        {
            if(k<=nc)
            {
                for(i=0;i<k;i++) s-=a[i];
                for(;i<n;i++) s+=a[i];
                printf("%d\n",s);
            }
            else
            {
                for(i=0;i<nc-1;i++) s-=a[i];
                if((k-nc)%2==0)
                {
                    s-=a[i];
                    for(i=nc;i<n;i++) s+=a[i];
                }
                else
                {
                    if(-a[i]<a[nc])
                    {
                        s+=a[i];
                        for(i=nc;i<n;i++) s+=a[i];
                    }
                    else
                    {
                        s-=a[i];
                        s-=a[nc];
                        for(i=nc+1;i<n;i++) s+=a[i];
                    }
                }
                printf("%d\n",s);
            }
        }
    }
    return 0;
}
