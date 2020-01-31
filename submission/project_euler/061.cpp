#include "bits/stdc++.h"
using namespace std;
const int N=6,MIN=1000,MAX=9999;
int a[]={ 1, 1, 3, 2, 5, 3};
int b[]={ 1, 0,-1,-1,-3,-2};
int c[]={ 2, 1, 2, 1, 2, 1};
vector <int> v[N],perm={0,1,2,3,4,5},ans;

void go(int i,string starts_with)
{
	if(i==6)
	{
		string a=to_string(ans[0]),b=to_string(ans.back());
		if(a.substr(0,2)!=b.substr(2)) return;
		cout<<accumulate(ans.begin(),ans.end(),0)<<endl;
		exit(0);
	}
	for(auto j:v[perm[i]])
	{
		string num=to_string(j);
		if(not ans.empty() and num.substr(0,2)!=starts_with) continue;
		ans.push_back(j);
		go(i+1,num.substr(2));
		ans.pop_back();
	}
}

int main()
{
	for(int i=0;i<N;i++)
		for(int j=1;(j*(a[i]*j+b[i])/c[i])<=MAX;j++)
			if((j*(a[i]*j+b[i])/c[i])>=MIN)
				v[i].push_back(j*(a[i]*j+b[i])/c[i]);

	do go(0,"");
	while(next_permutation(perm.begin(),perm.end()));
}