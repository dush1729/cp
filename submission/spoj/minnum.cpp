#include<stdio.h>
#include<string.h>
int main()
{
    char a[33];
    scanf("%s",a);
    while(a[0]!='-')
    {
        short l,i;short b[33]={},s=0;
        l=strlen(a);
        if((l==1)&&(a[0]=='0')) printf("0\n");
        else if(l==1) printf("1\n");
        else
        {
            b[0]=a[0]-'0';
            for(i=0;i<l;i++)
            {
                if(b[i]>=9)
                {
                    b[i+1]=10*(b[i]%9)+a[i+1]-'0';
                    b[i]=b[i]/9;
                }
                else
                {
                    b[i]=0;
                    b[i+1]=10*(a[i]-'0')+a[i+1]-'0';
                }
                s+=a[i]-'0';
            }
            if(s%9)
            {
                if(b[l-1]!=9)
                {
                    if(b[0]==0) i=1;
                    else i=0;
                    for(;i<l-1;i++) printf("%hd",b[i]);
                    printf("%hd",b[l-1]+1);
                }
                else
                {
                    for(i=l-1;b[i]==9;i--) b[i]=0;
                    if(i)
                    {
                        b[i]++;
                        if(b[0]==0) i=1;
                        else i=0;
                        for(;i<l;i++) printf("%hd",b[i]);
                    }
                    else
                    {
                        printf("1");
                        for(i=1;i<l;i++) printf("0");
                    }
                }
            }
            else
            {
                if(b[0]==0) i=1;
                else i=0;
                for(;i<l;i++) printf("%hd",b[i]);
            }
            printf("\n");
        }
        scanf("%s",a);
    }
    return 0;
}
