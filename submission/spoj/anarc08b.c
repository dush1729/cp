#include<stdio.h>
#include<math.h>
int p(int a)
{
    int i,z=1;
    for(i=1;i<=a;i++) z*=10;
    return z;
}
int main()
{
    char a[1000];
    scanf("%s",a);
    while(a[0]!='B')
    {
        int i,n,num1=0,num2=0;
        for(i=0;a[i]!='+';i+=3)
        {
            n=100*(a[i]-'0')+10*(a[i+1]-'0')+a[i+2]-'0';
            switch(n)
            {
                case 63:num1=10*num1+0;
                        break;
                case 10:num1=10*num1+1;
                        break;
                case 93:num1=10*num1+2;
                        break;
                case 79:num1=10*num1+3;
                        break;
                case 106:num1=10*num1+4;
                        break;
                case 103:num1=10*num1+5;
                        break;
                case 119:num1=10*num1+6;
                        break;
                case 11:num1=10*num1+7;
                        break;
                case 127:num1=10*num1+8;
                        break;
                case 107:num1=10*num1+9;
                        break;
            }
        }
        i++;
        for(;a[i]!='=';i+=3)
        {
            n=100*(a[i]-'0')+10*(a[i+1]-'0')+a[i+2]-'0';
            switch(n)
            {
                case 63:num2=10*num2;
                        break;
                case 10:num2=10*num2+1;
                        break;
                case 93:num2=10*num2+2;
                        break;
                case 79:num2=10*num2+3;
                        break;
                case 106:num2=10*num2+4;
                        break;
                case 103:num2=10*num2+5;
                        break;
                case 119:num2=10*num2+6;
                        break;
                case 11:num2=10*num2+7;
                        break;
                case 127:num2=10*num2+8;
                        break;
                case 107:num2=10*num2+9;
                        break;
            }
        }
        n=num1+num2;
        printf("%s",a);
        num1=log10(n)+1;
        num2=p(num1-1);
        for(i=0;i<num1;i++)
        {
            switch(n/num2)
            {
                case 0: printf("063");
                        break;
                case 1: printf("010");
                        break;
                case 2: printf("093");
                        break;
                case 3: printf("079");
                        break;
                case 4: printf("106");
                        break;
                case 5: printf("103");
                        break;
                case 6: printf("119");
                        break;
                case 7: printf("011");
                        break;
                case 8: printf("127");
                        break;
                case 9: printf("107");
                        break;
            }
            n=n-(n/num2)*num2;
            num2/=10;
        }
        printf("\n");
        scanf("%s",a);
    }
    return 0;
}
