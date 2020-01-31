#include<stdio.h>
int main()
{
    short N,a,b=0,c,d,e=0;
    for(a=0;a<10;a++)
    {
        scanf("%hd",&N);
        c=b;
        b=b+N;
        if((b>=100)&&(e==0))
        {
            if((b-100)>(100-c)) d=c;
            else d=b;
            e=1;
        }
        else if(e==0) d=b;
    }
    printf("%hd\n",d);
    return 0;
}
