#include<stdio.h>
#include<string.h>
int main()
{
    char a[102];
    while(scanf("%s",&a)!=EOF)
    {
        short i,l;short b[103]={};
        l=strlen(a);
        if(a[l-1]=='0')
        {
            i=l-1;
            while(a[i]=='0')
            {
                a[i]='9';
                i--;
            }
            a[i]--;
        }
        else a[l-1]--;
        for(i=l-1;i>=0;i--)
        {
            b[i+1]=b[i+1]+(a[i]-'0')*2;
            if(b[i+1]>9)
            {
                b[i+1]%=10;
                b[i]++;
            }
        }
        if(b[0]==0) i=1;
        else i=0;
        if((l==1)&&(a[0]=='0')) printf("1\n");
        else {for(;i<=l;i++) printf("%hd",b[i]);printf("\n");}
    }
    return 0;
}
