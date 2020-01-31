#include<stdio.h>
#include<math.h>
int main()
{
    short t;
    scanf("%hd",&t);
    while(t--)
    {
        long long N,low,mid,high;short z,c=0;
        scanf("%lld",&N);
        if(!(N&(N-1))) {printf("%lld 0\n",N);}
        else
        {
            z=log2(N)+1;
            low=1;high=pow(2,z);mid=(low+high)/2;
            while(mid!=N)
            {
                if(N>mid) {low=mid+1;c++;}
                else {high=mid-1;c++;}
                mid=(low+high)/2;
            }
            c++;
            printf("%lld %hd\n",(long long)pow(2,z),c);
        }
    }
    return 0;
}
