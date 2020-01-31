#include<stdio.h>
int main()
{
    unsigned char a[3][19];
    while(gets(a[0]))
    {
        gets(a[1]);
        gets(a[2]);
        unsigned short j=0;
        for(;;j+=3)
        {
            if((a[0][j+1]=='_')&&(a[1][j+1]=='_')&&(a[2][j+1]=='_'))
            {
                if(a[2][j+2]==' ') printf("2");
                else if(a[1][j]==' ') printf("3");
                else if(a[2][j]==' ') printf("5");
                else if(a[1][j+2]==' ') printf("6");
                else printf("8");
            }
            else
            {
                if((a[0][j+1]==' ')&&(a[1][j+1]==' ')&&(a[2][j+1]==' ')) printf("1");
                else if(a[0][j+1]==' ') printf("4");
                else if(a[1][j]==' ') printf("7");
                else if(a[1][j+1]==' ') printf("0");
                else printf("9");
            }
            if(a[0][j+3]=='\0') break;
        }
        printf("\n");
    }
    return 0;
}
