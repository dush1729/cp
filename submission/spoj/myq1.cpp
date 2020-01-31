#include<stdio.h>
int main()
{
    unsigned T;
    scanf("%u",&T);
    while(T--)
    {
        int n,c,r;
        scanf("%u",&n);
        if(n==1) printf("poor conductor\n");
        else
        {
            r=(n-2)/5;
            if(r%2)
            {
                c=(12-(n%10))%10;
                if(c==1) printf("%u W L\n",r+1);
                else if(c==2) printf("%u A L\n",r+1);
                else if(c==3) printf("%u A R\n",r+1);
                else if(c==4) printf("%u M R\n",r+1);
                else if(c==5) printf("%u W R\n",r+1);
            }
            else
            {
                c=(n-1)%10;
                if(c==1) printf("%u W L\n",r+1);
                else if(c==2) printf("%u A L\n",r+1);
                else if(c==3) printf("%u A R\n",r+1);
                else if(c==4) printf("%u M R\n",r+1);
                else if(c==5) printf("%u W R\n",r+1);
            }
        }
    }
    return 0;
}
