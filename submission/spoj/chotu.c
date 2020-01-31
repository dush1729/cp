#include<stdio.h>
#include<math.h>
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        float X,Y,e;
        scanf("%f%f",&X,&Y);
        e=sqrt(1-(Y/X)*(Y/X));
        printf("%.3f\n",2*e*X);
    }
    return 0;
}
