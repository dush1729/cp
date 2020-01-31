#include<stdio.h>
int main()
{
    while(1)
    {
        int n,i,j;
        scanf("%d",&n);
        if(n==-1) break;
        if(n!=1)
        {
            for(i=1;i<=2*n-1;i++) printf(" ");
            printf("_");
            for(i=1;i<=2*n-1;i++) printf(" ");
            printf("\n");
            for(i=1;i<=2*n-3;i++) printf(" ");
            printf("_/ \\_");
            for(i=1;i<=2*n-3;i++) printf(" ");
            printf("\n");
            for(i=3;i<=n;i++)
            {
                for(j=1;j<=2*(n-i)+1;j++) printf(" ");
                printf("_/ ");
                for(j=3;j<=i;j++) printf("\\_/ ");
                printf("\\_ ");
                for(j=1;j<=2*(n-i);j++) printf(" ");
                printf("\n");
            }
            for(i=1;i<=2*n;i++)
            {
                if(i&1)
                {
                    printf("/ ");
                    for(j=1;j<n;j++) printf("\\_/ ");
                    printf("\\");
                    printf("\n");
                }
                else
                {
                    for(j=1;j<n;j++) printf("\\_/ ");
                    printf("\\_/");
                    printf("\n");
                }
            }
            for(i=2;i<=n;i++)
            {
                for(j=1;j<i;j++) printf("  ");
                for(j=1;j<=n-i;j++) printf("\\_/ ");
                printf("\\_/");
                printf("\n");
            }
            printf("***\n");
        }
        else
        {
            printf(" _ \n");
            printf("/ \\\n");
            printf("\\_/\n");
            printf("***\n");
        }
    }
    return 0;
}
