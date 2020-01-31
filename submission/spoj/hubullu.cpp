#include<stdio.h>
main()
{
    int t,N,a;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &N, &a);
        if(a==0) printf("Airborne wins.\n");
        else printf("Pagfloyd wins.\n");
    }
}



