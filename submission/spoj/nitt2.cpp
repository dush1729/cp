#include<stdio.h>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        char a[50002];unsigned i,j,l=0,ds=0,z=1,s=0;
        fflush(stdin);
        scanf("%s",a);
        for(i=0;a[i]!='\0';i++)
        {
            l++;
            ds+=a[i]-'0';
        }
        j=1;
        for(i=l-1;i>=0;i--)
        {
            if(j%6==1) s+=(a[i]-'0')*1;
            else if(j%6==2) s+=(a[i]-'0')*3;
            else if(j%6==3) s+=(a[i]-'0')*2;
            else if(j%6==4) s+=(a[i]-'0')*6;
            else if(j%6==5) s+=(a[i]-'0')*4;
            else s+=(a[i]-'0')*5;
            j++;
            if(i==0) break;
        }
        if(s%7) s=0;
        else s=1;
        if((10*(a[l-2]-'0')+a[l-1]-'0')%4) z=0;
        else if(ds%9) z=0;
        if(z&&s) printf("Yes ");
        else printf("No ");
        z=1;
        if(ds%3) z=0;
        if(!((a[l-2]=='2')&&(a[l-1]=='5')||((a[l-2]=='5')&&(a[l-1]=='0'))
           ||((a[l-2]=='7')&&(a[l-1]=='5'))||(a[l-2]=='0')&&(a[l-1]=='0'))) z=0;
        if(z&&s) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
