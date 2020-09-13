#include "solution.hpp"
using namespace std;

const int N=1e5+20,C=2,L=30;

struct query
{
	int x,limit,idx;
};

vector <query> q;

bool cmp(struct query &a,struct query &b)
{
	return a.limit<b.limit;
}

struct trie
{
	int cnt;
	trie *nxt[C];
};
 
void add(int x,trie *node)
{
	for(int i=L-1;i>=0;i--)
	{
		int b=(x>>i)&1;
		if(node->nxt[b]==NULL) node->nxt[b]=new trie();
		node->nxt[b]->cnt++;
		node=node->nxt[b];
	}
}

int get(int x,trie *node)
{
	int ans=0;
	for(int i=L-1;i>=0;i--)
	{
		int b=(x>>i)&1;
		if(node->nxt[!b])
		{
			if(b==0) ans+=(1<<i);
			node=node->nxt[!b];
		}
		else
		{
			if(b==1) ans+=(1<<i);
			node=node->nxt[b];
		}
	}
	return ans;
}

class Solution {
	public:
	vector<int> solve(vector<int>& a, vector<vector<int>>& queries) {
		q.clear();
		for(int i=0;i<queries.size();i++)
			q.push_back({queries[i][0],queries[i][1],i});

		sort(q.begin(),q.end(),cmp);
		sort(a.begin(),a.end());

		vector <int> ans(q.size(),-1);
		auto head=new trie();
		int ptr=0;
		for(auto qu:q)
		{
			while(ptr<a.size() and a[ptr]<=qu.limit)
			{
				add(a[ptr],head);
				ptr++;
			}
			if(ptr==0) continue;

			
			ans[qu.idx]=get(qu.x,head);
		}


		
		return ans;
	}
};
