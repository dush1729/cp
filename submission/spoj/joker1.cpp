#include<stdio.h>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        short N;
        scanf("%hd",&N);
        short K[N],i,j,temp;long long p=1;
        for(i=0;i<N;i++)
            scanf("%hd",&K[i]);
        for(i=0;i<N-1;i++)
        {
            for(j=0;j<N-1-i;j++)
            {
                if(K[j]>K[j+1])
                {
                    temp=K[j];
                    K[j]=K[j+1];
                    K[j+1]=temp;
                }
            }
        }
        for(i=0;i<N;i++)
        {
            p=p*(K[i]-i);
            if(p>1000000007) p%=1000000007;
        }
        p%=1000000007;
        printf("%lld\n",p);
    }
    printf("KILL BATMAN\n");
    return 0;
}
