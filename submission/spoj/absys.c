#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char a[43];
        int i,b=0,c=0,d=0;
        fflush(stdin);
        gets(a);
        while(a[0]=='\0')
        {
            fflush(stdin);
            gets(a);
        }
        for(i=0;a[i]!=' ';i++)
        {
            if(a[i]=='m')
            {
                b=-1;
                break;
            }
            b=b*10+(a[i]-'0');
        }
        for(;a[i]!=' ';i++);
        i+=3;
        for(;a[i]!=' ';i++)
        {
            if(a[i]=='m')
            {
                c=-1;
                break;
            }
            c=c*10+(a[i]-'0');
        }
        for(;a[i]!=' ';i++);
        i+=3;
        for(;a[i]!='\0';i++)
        {
            if(a[i]=='m')
            {
                d=-1;
                break;
            }
            d=d*10+(a[i]-'0');
        }
        if(b==-1) printf("%d + %d = %d\n",d-c,c,d);
        else if(c==-1) printf("%d + %d = %d\n",b,d-b,d);
        else printf("%d + %d = %d\n",b,c,b+c);
    }
    return 0;
}
