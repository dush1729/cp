#include<stdio.h>
#include<string.h>
int main()
{
    short z=1;
    for(;z<=10;z++)
    {
        char a[101],b[101],t[101];short ad[102]={},sb[101]={},i,la,lb;
        scanf("%s",a);
        scanf("%s",b);
        la=strlen(a);
        lb=strlen(b);
        for(i=la-1;i>=la-lb;i--)
        {
            ad[i+1]=ad[i+1]+a[i]-'0'+b[i-la+lb]-'0';
            if(ad[i+1]>9)
            {
                ad[i+1]=ad[i+1]%10;
                ad[i]++;
            }
        }
        for(;i>=0;i--)
        {
            ad[i+1]=a[i]-'0'+ad[i+1];
            if(ad[i+1]>9)
            {
                ad[i+1]=ad[i+1]%10;
                ad[i]++;
            }
        }
        for(i=la-1;i>=la-lb;i--)
        {
            if(sb[i]+a[i]-b[i-la+lb]<0)
            {
                sb[i]=a[i]+10-b[i-la+lb]+sb[i];
                sb[i-1]--;
            }
            else sb[i]=sb[i]+a[i]-b[i-la+lb];
        }
        for(;i>=0;i--)
        {
            if(sb[i]<0)
            {
                if(a[i]-'0'+sb[i]<0) {sb[i]=a[i]-'0'+10+sb[i];sb[i-1]--;}
                else sb[i]=a[i]-'0'+sb[i];
            }
            else sb[i]=a[i]-'0'+sb[i];
        }
        for(i=0;ad[i]==0;i++);
        if(ad[i]==1) {ad[i+1]+=10;i++;}
        for(;i<=la;i++)
        {
            printf("%hd",ad[i]/2);
            if(ad[i]%2) ad[i+1]+=10;
        }
        printf("\n");
        for(i=0;sb[i]==0;i++);
        if(sb[i]==1) {sb[i+1]+=10;i++;}
        for(;i<la;i++)
        {
            printf("%hd",sb[i]/2);
            if(sb[i]%2) sb[i+1]+=10;
        }
        printf("\n");
    }
}
