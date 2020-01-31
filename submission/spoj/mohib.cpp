#include<stdio.h>
int main()
{
	short t;
	scanf("%hd",&t);
	while(t--)
    {
        int x,avg;
        scanf("%d%d",&x,&avg);
        printf("%d\n",(avg-x)*(avg+1)-((avg-x)*(avg-x-1)/2));
    }
    return 0;
}
