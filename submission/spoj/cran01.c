#include<stdio.h>
int main()
{
    short T;
    scanf("%hd",&T);
    while(T--)
    {
        short n,m,x,y;
        scanf("%hd%hd%hd%hd",&n,&m,&x,&y);
        if(x>=(n+2)/2)
        {
            if(y>=(m+2)/2) printf("%hd\n",x+y-2);
            else printf("%hd\n",x+m-y-1);
        }
        else
        {
            if(y>=(m+2)/2) printf("%hd\n",n+y-x-1);
            else printf("%hd\n",n+m-x-y);
        }
    }
    return 0;
}
