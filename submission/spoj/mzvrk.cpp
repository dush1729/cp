#include<stdio.h>
#include<math.h>
unsigned long long whi(unsigned long long a)
{
    unsigned long long s=0,i;
    for(i=1;i<=a;i<<=1) s+=i*(1+((a-i)/(i<<1)));
    return s;
}
int main()
{
    unsigned long long A,B;
    scanf("%llu%llu",&A,&B);
    printf("%llu\n",whi(B)-whi(A-1));
    return 0;
}
