#include<stdio.h>
#include<math.h>
int po(int a,int b)
{
    int i,p=1;
    for(i=1;i<=b;i++) p*=a;
    return p;
}
int main()
{
    while(1)
    {
        char y[5];
        fflush(stdin);
        scanf("%s",y);
        int n,z;
        n=(10*(y[0]-'0')+y[1]-'0')*po(10,y[3]-'0');
        if(n==0) break;
        if((n&(n-1))==0) printf("1\n");
        else
        {
            z=log2l(n);
            z=po(2,z);
            printf("%d\n",1+2*(n-z));
        }
    }
    return 0;
}
