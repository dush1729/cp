#include<stdio.h>
unsigned gcd(unsigned a,unsigned b)
{
    if(a%b) return gcd(b,a%b);
    else return b;
}
int main()
{
    char a[21];
    scanf("%s",a);
    while(a[0]!='*')
    {
        unsigned p=1;short i,z=1;
        for(i=0;a[i]!='\0';i++) if(a[i]=='Y') p=(p/gcd(p,i+1))*(i+1);
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='N')
            {
                if(p%(i+1)==0)
                {
                    z=0;
                    break;
                }
            }
        }
        if(z) printf("%u\n",p);
        else printf("-1\n");
        fflush(stdin);
        scanf("%s",a);
    }
    return 0;
}
