#include<stdio.h>
int main()
{
    short P;
    scanf("%hd",&P);
    while(P--)
    {
        char a[41];short i,d,b[8]={0};
        scanf("%hd",&d);
        scanf("%s",a);
        for(i=0;i<38;i++)
        {
            if((a[i]=='T')&&(a[i+1]=='T')&&(a[i+2]=='T')) b[0]++;
            else if((a[i]=='T')&&(a[i+1]=='T')&&(a[i+2]=='H')) b[1]++;
            else if((a[i]=='T')&&(a[i+1]=='H')&&(a[i+2]=='T')) b[2]++;
            else if((a[i]=='T')&&(a[i+1]=='H')&&(a[i+2]=='H')) b[3]++;
            else if((a[i]=='H')&&(a[i+1]=='T')&&(a[i+2]=='T')) b[4]++;
            else if((a[i]=='H')&&(a[i+1]=='T')&&(a[i+2]=='H')) b[5]++;
            else if((a[i]=='H')&&(a[i+1]=='H')&&(a[i+2]=='T')) b[6]++;
            else if((a[i]=='H')&&(a[i+1]=='H')&&(a[i+2]=='H')) b[7]++;
        }
        printf("%hd ",d);
        for(i=0;i<8;i++) printf("%hd ",b[i]);
        printf("\n");
    }
    return 0;
}








