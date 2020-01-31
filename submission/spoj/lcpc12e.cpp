#include<stdio.h>
#include<math.h>
int main()
{
    short i,T;
    scanf("%hd",&T);
    for(i=1;i<=T;i++)
    {
        double x1,y1,x2,y2,r1,l,r2,d,cth;
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&r1,&l);
        r2=l/sqrt(2);
        d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(d>(r1+r2)) printf("%hd. No problem\n",i);
        else
        {
            cth=(d*d+r1*r1-r2*r2)/(2*r1*d);
            printf("%hd. %.3lf\n",i,2*r1*sqrt(1-cth*cth));
        }
    }
    return 0;
}




