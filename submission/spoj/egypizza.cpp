#include<stdio.h>
int main()
{
    short N,n,c1=0,c2=0,c3=0,c;
    scanf("%hd",&N);
    while(N--)
    {
        scanf("%hd/%hd",&n,&c);
        if((n==1)&&(c==4)) c1++;
        else if((n==1)&&(c==2)) c2++;
        else c3++;
    }
    c=0;
    c+=c2/2;
    c2=c2&1;
    if(c1>c3)
    {
        c+=c3;
        c1=c1-c3;
        c+=c1/4;
        if((c1%4==3)&&c2) c+=2;
        else if(c1%4) c++;
        else if(c2) c++;
        c++;
        printf("%hd\n",c);
    }
    else
    {
        c+=c3;
        if(c2) c++;
        c++;
        printf("%hd\n",c);
    }
    return 0;
}
