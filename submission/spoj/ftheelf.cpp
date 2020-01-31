#include<stdio.h>
#include<math.h>
int main()
{
    short V,H;
    scanf("%hd%hd",&V,&H);
    while(V!=-1)
    {
        printf("%.6lf\n",V*sqrt(V*V+19.6*H)/9.8);
        scanf("%hd%hd",&V,&H);
    }
    return 0;
}
