#include<stdio.h>
main()
{
    int N;
    scanf("%d", &N);
    while(N)
    {
        printf("%d\n", (3*N+2)*(N+1)/2);
        scanf("%d", &N);
    }
}




