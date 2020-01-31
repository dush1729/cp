#include<stdio.h>
#include<math.h>
unsigned long long pp(unsigned long long b)
{
    unsigned long long i,p=1;
    for(i=1;i<=b;i++)
    {
        p*=5;
    }
    return p;
}
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        unsigned long long n,r,i,y,z;
        scanf("%llu",&n);
        r=logl((4*n+1)/5)/logl(5);
        y=(pp(r+1)-5)/4;
        for(i=r;i>0;i--)
        {
            z=(n-1-y)/pp(i);
            z%=5;
            switch(z)
            {
                case 0: printf("m");break;
                case 1: printf("a");break;
                case 2: printf("n");break;
                case 3: printf("k");break;
                case 4: printf("u");break;
            }
        }
        z=n%5;
        switch(z)
        {
            case 1: printf("m");break;
            case 2: printf("a");break;
            case 3: printf("n");break;
            case 4: printf("k");break;
            case 0: printf("u");break;
        }
        printf("\n");
    }
    return 0;
}
