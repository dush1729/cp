#include<stdio.h>
#include<math.h>
int main()
{
    char a[50],b[50];
    while(gets(a))
    {
        long long n=0,i,b1=0,b2=0,d,p1,p2,c=1;
        for(i=0;a[i]==' ';i++);
        p1=i;
        for(;a[i]!=' ';i++);
        p2=i-1;
        for(;a[i]==' ';i++);
        for(;a[i]!=' ';i++) b1=b1*10+(a[i]-'0');
        for(;a[i]==' ';i++);
        for(;a[i]!='\0';i++) b2=b2*10+(a[i]-'0');
        for(i=p2;i>=p1;i--)
        {
            if(a[i]>'9')
            {
                n+=(a[i]-'A'+10)*c;
                c*=b1;
            }
            else
            {
                n+=(a[i]-'0')*c;
                c*=b1;
            }
        }
        d=1+(logl(n)/logl(b2));
        c=0;
        if(d>7) printf("ERROR\n");
        else
        {
            while(n)
            {
                d=n%b2;
                if(d>=10) b[c]=(d%10)+'A';
                else b[c]='0'+d;
                n/=b2;
                c++;
            }
            for(i=0;i<7-c;i++) printf(" ");
            for(i=c-1;i>=0;i--) printf("%c",b[i]);
            printf("\n");
        }
        fflush(stdin);
    }
    return 0;
}
