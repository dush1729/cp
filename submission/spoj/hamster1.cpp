#include<stdio.h>
#include<math.h>
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        short v,k1,k2;double a,M;
        scanf("%hd%hd%hd",&v,&k1,&k2);
        if(!k2)
        {
            a=M_PI_4;
            M=v*v*(2*k1*sin(2*a)+k2*sin(a)*sin(a))/20;
            printf("%.3lf %.3lf\n",a,M);
        }
        else
        {
            a=(M_PI-atan2(4*k1,k2))/2;
            M=v*v*(2*k1*sin(2*a)+k2*sin(a)*sin(a))/20;
            printf("%.3lf %.3lf\n",a,M);
        }
    }
    return 0;
}
