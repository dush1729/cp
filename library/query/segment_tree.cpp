#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20;

int n,a[N],lazy[N<<2];

struct node
{
	int val;
}tree[N<<2];

void build(int node,int start,int end)
{
	struct node &parent=tree[node];
	if(start==end) parent.val=a[start];
	else
	{
		int mid=(start+end)>>1;
		build(node<<1,start,mid);
		build((node<<1)+1,mid+1,end);

		struct node left_child=tree[node<<1];
		struct node right_child=tree[(node<<1)+1];
		parent.val=left_child.val+right_child.val;
	}
}

void point_update(int node,int start,int end,int idx,int val)
{
	struct node &parent=tree[node];
	if(start==end)
	{
		a[idx]+=val;
		parent.val+=val;
	}
	else
	{
		int mid=(start+end)>>1;
		if(start<=idx and idx<=mid) point_update(node<<1,start,mid,idx,val);
		else point_update((node<<1)+1,mid+1,end,idx,val);

		struct node left_child=tree[node<<1];
		struct node right_child=tree[(node<<1)+1];
		parent.val=left_child.val+right_child.val;
	}
}

int no_lazy_query(int node,int start,int end,int l,int r)
{
	if(r<start or end<l) return 0;
	struct node &parent=tree[node];
	if(l<=start and end<=r) return parent.val;

	int mid=(start+end)>>1;
	int p1=no_lazy_query(node<<1,start,mid,l,r);
	int p2=no_lazy_query((node<<1)+1,mid+1,end,l,r);
	return (p1+p2);
}

void no_lazy_update(int node,int start,int end,int l,int r,int val)
{
	if(start>end or start>r or end<l) return;
	struct node &parent=tree[node];
	if(start==end)
	{
		parent.val+=val;
		return;
	}

	int mid=(start+end)>>1;
	no_lazy_update(node<<1,start,mid,l,r,val);
	no_lazy_update((node<<1)+1,mid+1,end,l,r,val);
	struct node left_child=tree[node<<1];
	struct node right_child=tree[(node<<1)+1];
	parent.val=left_child.val+right_child.val;
}

void update(int node,int start,int end,int l,int r,int val)
{
	struct node &parent=tree[node];
	if(lazy[node]!=0)
	{
		parent.val+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[node<<1]+=lazy[node];
			lazy[(node<<1)+1]+=lazy[node];
		}
		lazy[node]=0;
	}

	if(start>end or start>r or end<l) return;

	if(start>=l and end<=r)
	{
		parent.val+=(end-start+1)*val;
		if(start!=end)
		{
			lazy[node<<1]+=val;
			lazy[(node<<1)+1]+=val;
		}
		return;
	}

	int mid=(start+end)>>1;
	update(node<<1,start,mid,l,r,val);
	update((node<<1)+1,mid+1,end,l,r,val);
	struct node left_child=tree[node<<1];
	struct node right_child=tree[(node<<1)+1];
	parent.val=left_child.val+right_child.val;
}

int query(int node,int start,int end,int l,int r)
{
	if(start>end or start>r or end<l) return 0;
	struct node &parent=tree[node];
	if(lazy[node]!=0)
	{
		parent.val+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[node<<1]+=lazy[node];
			lazy[(node<<1)+1]+=lazy[node];
		}
		lazy[node]=0;
	}

	if(start>=l and end<=r) return parent.val;

	int mid=(start+end)>>1;
	int p1=query(node<<1,start,mid,l,r);
	int p2=query((node<<1)+1,mid+1,end,l,r);
	return (p1 + p2);
}

int main()
{
	//https://www.spoj.com/problems/HORRIBLE/
}