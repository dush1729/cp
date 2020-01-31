#include<stdio.h>
int main()
{
    short G,B;
    scanf("%hd%hd",&G,&B);
    while(G!=-1)
    {
        if(G>=B)
        {
            if(G%(B+1)==0) printf("%hd\n",G/(B+1));
            else printf("%hd\n",(G/(B+1))+1);
        }
        else
        {
            if(B%(G+1)==0) printf("%hd\n",B/(G+1));
            else printf("%hd\n",(B/(G+1))+1);
        }
        scanf("%hd%hd",&G,&B);
    }
    return 0;
}
