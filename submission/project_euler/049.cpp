#include <bits/stdc++.h>
using namespace std;
const int MAX=1e4+20;
int i,j,k;
bool prime[MAX];
int main()
{
	for(i=2;i<MAX;i++) prime[i]=true;
	for(i=2;i*i<MAX;i++)
		if(prime[i])
			for(j=i*i;j<MAX;j+=i)
				prime[j]=false;
	
	for(int num=1e3;num<1e4;num++)
	{
		string a=to_string(num);
		sort(a.begin(),a.end());
		vector <string> v;
		
		do if(prime[stoi(a)]) v.push_back(a);
		while(next_permutation(a.begin(),a.end()));
		
		if(v.size()<3) continue;
		
		for(i=0;i<v.size() and v[i][0]!='0';i++)
			for(j=i+1;j<v.size();j++)
				for(k=j+1;k<v.size();k++)
					if(2*stoi(v[j])==stoi(v[i])+stoi(v[k]))
						cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
	}
}
