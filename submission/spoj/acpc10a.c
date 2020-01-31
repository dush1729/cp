#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    while(c)
    {
        if(b==(a+c)/2.0)
            printf("AP %d\n",2*c-b);
        else printf("GP %d\n",c*c/b);
        scanf("%d%d%d",&a,&b,&c);
    }
    return 0;
}
