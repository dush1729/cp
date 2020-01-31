#include<stdio.h>
int p(int a)
{
    int i,b=1;
    for(i=1;i<=a;i++) b*=10;
    return b;
}
int gcd(int a,int b)
{
    if(a%b) return gcd(b,a%b);
    else return b;
}
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        char a[20];int i,b=0,c=0;
        fflush(stdin);
        scanf("%s",a);
        for(i=0;(a[i]!='.')&&(a[i]!='\0');i++);
        i++;
        if(a[i-1]=='\0') printf("1\n");
        else
        {
            for(;a[i]!='\0';i++)
            {
                b++;
                c=10*c+a[i]-'0';
            }
            b=p(b);
            printf("%d\n",b/gcd(b,c));
        }
    }
    return 0;
}
