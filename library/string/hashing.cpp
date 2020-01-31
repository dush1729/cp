#include "bits/stdc++.h"
using namespace std;

//CNT - 26 for alphabet, 10 for decimal
//START - 'a' for alphabet, '0' for decimal
const int CNT=10;
const char START='0';
const vector <int> MOD={1000000007,573161801};

vector <long long> calculate_left_hash(string a,int mod)
{
	vector <long long> v;
	v.push_back(0);
	for(int i=0;i<a.size();i++) v.push_back((v.back()*CNT+a[i]-START)%mod);
	return v;
}

vector <long long> calculate_right_hash(string a,int mod)
{
	reverse(a.begin(),a.end());
	vector <long long> v;
	v.push_back(0);
	for(int i=0;i<a.size();i++) v.push_back((v.back()*CNT+a[i]-START)%mod);
	v.push_back(0),reverse(v.begin(),v.end()),v.push_back(0),v.pop_back();
	return v;
}

vector <long long> calculate_power(int n,long long mod)
{
	vector <long long> p;
	p.push_back(1);
	for(int i=0;i<n;i++) p.push_back((p.back()*CNT)%mod);
	return p;
}

long long sub_left_hash(vector <long long> &v,vector <long long> &p,int l,int r,int mod)
{
	return (v[r]-(v[l-1]*p[r-l+1])%mod+mod)%mod;
}

long long sub_right_hash(vector <long long> &v,vector <long long> &p,int l,int r,int mod)
{
	swap(l,r);
	return (v[r]-(v[l+1]*p[l-r+1])%mod+mod)%mod;
}

vector <int> longest_palin_odd(string a,vector <vector <long long>> lh,vector <vector <long long>> rh,vector <int> mod,vector <vector <long long>> p)
{
	a="$"+a;
	int n=a.size()-1;
	vector <int> v;
	for(int i=1;i<=n;i++)
	{
		int lo=1,hi=min(i,n-i+1),mid,ans=-1;
		while(lo<=hi)
		{
			mid=(lo+hi)/2;

			bool okay=true;
			for(int j=0;j<lh.size() and okay;j++)
				if(sub_left_hash(lh[j],p[j],i-mid+1,i+mid-1,mod[j])!=sub_right_hash(rh[j],p[j],i-mid+1,i+mid-1,mod[j]))
					okay=false;
			if(okay) lo=mid+1,ans=2*mid-1;
			else hi=mid-1;
		}
		v.push_back(ans);
	}
	return v;
}

vector <int> longest_palin_even(string a,vector <vector <long long>> lh,vector <vector <long long>> rh,vector <int> mod,vector <vector <long long>> p)
{
	a="$"+a;
	int n=a.size()-1;
	vector <int> v;
	for(int i=1;i<=n;i++)
	{
		int lo=1,hi=min(i,n-i),mid,ans=-1;
		while(lo<=hi)
		{
			mid=(lo+hi)/2;

			bool okay=true;
			for(int j=0;j<lh.size() and okay;j++)
				if(sub_left_hash(lh[j],p[j],i-mid+1,i+mid,mod[j])!=sub_right_hash(rh[j],p[j],i-mid+1,i+mid,mod[j]))
					okay=false;
			if(okay) lo=mid+1,ans=2*mid;
			else hi=mid-1;
		}
		v.push_back(ans);
	}
	return v;
}

int main()
{
	//https://www.interviewbit.com/problems/longest-palindromic-substring/
	string a;
	cin>>a;

	vector <vector <long long>> left_hash,right_hash,power;
	for(auto mod:MOD)
	{
		left_hash.push_back(calculate_left_hash(a,mod));
		right_hash.push_back(calculate_right_hash(a,mod));
		power.push_back(calculate_power(a.size(),mod));
	}

	vector <int> odd=longest_palin_odd(a,left_hash,right_hash,MOD,power);
	vector <int> even=longest_palin_even(a,left_hash,right_hash,MOD,power);

	for(auto i:odd) cout<<i<<" ";cout<<endl;
	for(auto i:even) cout<<i<<" ";cout<<endl;
}