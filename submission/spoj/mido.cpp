#include<stdio.h>
int main()
{
    short N,team,MM=0,SS=0,t1=0,t2=0,m1=0,s1=0,sum1=0,sum2=0;
    scanf("%hd",&N);
    while(N--)
    {
        m1=MM;s1=SS;
        scanf("%hd %hd:%hd",&team,&MM,&SS);
        if(t1>t2)
        {
            sum1=sum1+(MM-m1)*60+(SS-s1);
        }
        else if(t2>t1)
        {
            sum2=sum2+(MM-m1)*60+(SS-s1);
        }
        if(team==1) t1++; else t2++;
    }
    if(t1>t2)
    {
        sum1=sum1+(47-MM)*60+(60-SS);
    }
    else if(t2>t1)
    {
        sum2=sum2+(47-MM)*60+(60-SS);
    }
    printf("%.2d:%.2d\n%.2d:%.2d",sum1/60,sum1%60,sum2/60,sum2%60);
    return 0;
}
