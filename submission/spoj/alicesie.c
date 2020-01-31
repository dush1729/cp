#include<stdio.h>
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        int N;
        scanf("%d",&N);
        printf("%d\n",(N+1)/2);
    }
    return 0;
}
