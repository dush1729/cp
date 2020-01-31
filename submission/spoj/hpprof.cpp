#include<stdio.h>
int main()
{
    char a[21];int i,s[20]={};
    fflush(stdin);
    scanf("%s",a);
    s[0]=1;
    for(i=1;a[i]!='\0';i++)
    {
        s[i]=s[i-1];
        if((a[i-1]=='0')||(a[i-1]>='3')||((a[i-1]=='2')&&(a[i]>='1'))) continue;
        if(i>1) s[i]+=s[i-2];
        else s[i]++;
    }
    printf("%d\n",s[i-1]);
    return 0;
}
