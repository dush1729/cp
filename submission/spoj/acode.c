#include<stdio.h>
int main()
{
    while(1)
    {
        char a[5001];int i,n;unsigned long long s[5000]={};
        fflush(stdin);
        scanf("%s",a);
        if(a[0]=='0') break;
        s[0]=1;
        for(i=1;a[i]!='\0';i++)
        {
            if(a[i]=='0')
            {
                if(i>1) s[i]=s[i-2];
                else s[i]=s[i-1];
                continue;
            }
            else s[i]=s[i-1];
            n=10*(a[i-1]-'0')+(a[i]-'0');
            if((i>1)&&(a[i-1]!='0')&&(n<=26)&&(n>=1)) s[i]+=s[i-2];
            else if((i==1)&&(n<=26)) s[i]++;
        }
        printf("%llu\n",s[i-1]);
    }
    return 0;
}
