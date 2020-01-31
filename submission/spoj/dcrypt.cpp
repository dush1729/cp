#include<stdio.h>
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        short key;char a[100001];int i;
        scanf("%hd",&key);
        scanf("%s",a);
        if(key<26)
        {
            for(i=0;a[i]!='\0';i++)
            {
                if((a[i]>=65)&&(a[i]<=90))
                {
                    if(90-a[i]-key<0) printf("%c",key+a[i]-26);
                    else printf("%c",a[i]+key);
                }
                else if((a[i]>=97)&&(a[i]<=122))
                {
                    if(122-a[i]-key<0) printf("%c",key+a[i]-26);
                    else printf("%c",a[i]+key);
                }
                else printf(" ");
            }
            printf("\n");
        }
        else
        {
            key-=26;
            for(i=0;a[i]!='\0';i++)
            {
                if((a[i]>=65)&&(a[i]<=90))
                {
                    if(90-a[i]-key<0) printf("%c",key+a[i]+6);
                    else printf("%c",a[i]+key+32);
                }
                else if((a[i]>=97)&&(a[i]<=122))
                {
                    if(122-a[i]-key<0) printf("%c",key+a[i]-58);
                    else printf("%c",a[i]+key-32);
                }
                else printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
