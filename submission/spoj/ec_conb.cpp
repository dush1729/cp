#include<stdio.h>
#include<math.h>
main()
{
    short t,a;int n,b=0;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n%2) printf("%d\n", n);
        else
        {
            while(n%2==0)
                n=n/2;
            a=log2(n);
            while(a)
            {
                b=b+(n%2)*pow(2,a);
                n=n/2;
                a=a-1;
            }
            b++;
            printf("%d\n", b);
        }
        b=0;
    }
}


