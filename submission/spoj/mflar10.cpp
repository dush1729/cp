#include<stdio.h>
int main()
{
    char a[1000];
    gets(a);
    while(a[0]!='*')
    {
        short i,z=1;char b;
        for(i=0;a[i]==' ';i++);
        b=a[i];
        if(b>=97) b-=32;
        for(;a[i]!='\0';i++)
        {
            if(a[i]==' '&&(a[i+1]!=b)&&(a[i+1]!=b+32)) {z=0;break;}
        }
        if(z) printf("Y\n");
        else printf("N\n");
        gets(a);
    }
    return 0;
}
