#include<stdio.h>
int main()
{
    char a[1010],f=0,u=0,i;
    fflush(stdin);
    scanf("%s",a);
    for(i=0;a[i+1]!='\0';i++)
    {
        if((a[i]=='0')&&(a[i+1]=='0')) f++;
        else if((a[i]=='0')&&(a[i+1]=='1')) u++;
    }
    if((a[i]=='0')&&(a[0]=='0')) f++;
    else if((a[i]=='0')&&(a[0]=='1')) u++;
    if(u==0) printf("EQUAL\n");
    else if(f==u) printf("EQUAL\n");
    else if(f>u) printf("SHOOT\n");
    else printf("ROTATE\n");
    return 0;
}
