#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20;

string text,pattern;
int n,m,p[N];

void preprocess()
{
	for(int j=0,i=1;i<m;i++)
	{
		while(j!=0 and pattern[i]!=pattern[j])
		{
			j--;
			if(j==0) break;
			j=p[j];
		}
		if(pattern[i]==pattern[j]) p[i]=++j;
		else p[i]=0;
	}
}

bool find()
{
	for(int i=0,j=0;i<n;i++)
	{
		while(j!=0 and text[i]!=pattern[j])
		{
			j--;
			if(j==0) break;
			j=p[j];
		}
		if(text[i]==pattern[j]) j++;
		else j=0;
		if(j==m) return true;
	}
	return false;
}

int main()
{
	cin>>text>>pattern;

	n=text.size();
	m=pattern.size();

	preprocess();

	if(find()==true) cout<<"FOUND!";
	else cout<<"Not found";
}
