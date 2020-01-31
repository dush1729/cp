#include<stdio.h>
main()
{
    long long int s=0;
    short t,d,m,y,a[12],b,c;
    a[1]=31,a[2]=28,a[3]=31,a[4]=30,a[5]=31,a[6]=30,
    a[7]=31,a[8]=31,a[9]=30,a[10]=31,a[11]=30,a[12]=31;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &d, &m, &y);
        s=(y-2012)*365+d;
        for(b=1;b<m;b++)
            s=s+a[b];
        for(c=2012;c<=y;c+=4)
        {
            if(c%4==0)
                {if(c%100!=0) s++;
                else if(c%400==0) s++;}
        }
        if( ((y%4==0) && (y%100!=0)) || (y%400==0) )
            {if( (m==1) || ((m==2) && (d<=29)) ) s--;}
        switch(s%7)
        {
            case 1: printf("Sunday\n");break;
            case 2: printf("Monday\n");break;
            case 3: printf("Tuesday\n");break;
            case 4: printf("Wednesday\n");break;
            case 5: printf("Thursday\n");break;
            case 6: printf("Friday\n");break;
            case 0: printf("Saturday\n");break;
        }
        c=0;
    }
}


