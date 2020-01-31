#include<stdio.h>
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        char a[1000];short i,pos,b[100]={0},max=0,max2=0;
        scanf(" %[^\n]s",a);
        for(i=0;a[i]!='\0';i++)
            b[a[i]]++;
        for(i=65;i<=90;i++)
            if(b[i]>=max) {max=b[i];pos=i;}
        for(i=65;i<=90;i++)
            if((b[i]>=max2)&&(i!=pos)) max2=b[i];
        if(max>max2)
        {
            short diff=pos-69;
            if(diff<0) {diff=pos-43;printf("%d ",diff);}
            else printf("%hd ",diff);
            for(i=0;a[i]!='\0';i++)
            {
                if(a[i]==32) printf(" ");
                else if(a[i]-diff>=65)
                {
                    a[i]=a[i]-diff;
                    printf("%c",a[i]);
                }
                else
                {
                    a[i]=a[i]+26-diff;
                    printf("%c",a[i]);
                }
            }
            printf("\n");
        }
        else printf("NOT POSSIBLE\n");
    }
    return 0;
}
