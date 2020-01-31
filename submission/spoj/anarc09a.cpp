#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t=1;
    while(1)
    {
        char a[2001],b[2000];int top=-1,i,c=0;
        cin>>a;
        if(a[0]=='-') break;
        for(i=0;a[i]!='\0';i++)
        {
            if(a[i]=='{') b[++top]='{';
            else
            {
                if(top==-1) c++;
                else top--;
            }
        }//printf("%d %d\n",c,top);
        printf("%d. %d\n",t++,(c+top+1+(c%2)+((top+1)%2))/2);
    }
    return 0;
}
