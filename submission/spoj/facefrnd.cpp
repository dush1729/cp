#include<stdio.h>
int main()
{
    short N,i,j,M,a[9999]={},b[100][100],c[100],f=0;
    scanf("%hd",&N);
    for(i=0;i<N;i++)
    {
        short f1;
        scanf("%hd",&f1);
        a[f1]++;
        scanf("%hd",&c[i]);
        for(j=0;j<c[i];j++) scanf("%hd",&b[i][j]);
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<c[i];j++) if(a[b[i][j]]!=1) {a[b[i][j]]++;f++;}
    }
    printf("%hd\n",f);
    return 0;
}
