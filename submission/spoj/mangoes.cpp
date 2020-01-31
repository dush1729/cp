#include<stdio.h>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        printf("%ld\n",((long long)(N-2+(N%2))*(N-2+(N%2))/4)%N);
    }
    return 0;
}
