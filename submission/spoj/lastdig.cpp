#include<stdio.h>
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        int b;short a,c[10][4]={{0,0,0,0},{1,1,1,1},{2,4,8,6},{3,9,7,1},{4,6,4,6},{5,5,5,5},
                                {6,6,6,6},{7,9,3,1},{8,4,2,6},{9,1,9,1}};
        scanf("%hd%d",&a,&b);
        if(b==0) printf("1\n");
        else printf("%hd\n",c[a%10][(b+3)%4]);
    }
}
