#include<stdio.h>
int main()
{
    char a[501],b[501];
    scanf("%s %s",a,b);
    while(a[0]!='*')
    {
        short i,c=0,z;
        for(i=0;a[i]!='\0';i++)
        {
            z=0;
            while((a[i]!='\0')&&(a[i]!=b[i]))
            {
                i++;
                z++;
            }
            if(z>0) c++;
            if(a[i]=='\0') break;
        }
        printf("%hd\n",c);
        fflush(stdin);
        scanf("%s %s",a,b);
    }
    return 0;
}
