#include<bits/stdc++.h>
int main()
{
    char a[1001],b[1001];
    while(scanf(" %s %s",a,b)!=EOF)
    {
        int la,lb,i,c1[26]={},c2[26]={},j,m;
        la=strlen(a);
        lb=strlen(b);
        for(i=0;i<la;i++) c1[a[i]-'a']++;
        for(i=0;i<lb;i++) c2[b[i]-'a']++;
        for(i=0;i<26;i++)
        {
            m=(c1[i]<c2[i]?c1[i]:c2[i]);
            for(j=0;j<m;j++) printf("%c",i+'a');
        }
        printf("\n");
    }
    return 0;
}
