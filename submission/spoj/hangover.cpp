#include<stdio.h>
int main()
{
    float a,c=0,b;
    scanf("%f",&a);
    while(a)
    {
        for(b=2;c<=a;b++)
        {
            c+=(1/b);
        }
        printf("%.0f card(s)\n",b-2);
        c=0;
        scanf("%f",&a);
    }
    return 0;
}
