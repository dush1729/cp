#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char a[11];int i,z=1,l;
        fflush(stdin);
        scanf("%s",a);
        l=strlen(a);
        for(i=0;i<l/2;i++)
        {
            if(a[i]!=a[l-i-1])
            {
                z=0;
                break;
            }
        }
        if(z) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
