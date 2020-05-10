#include "bits/stdc++.h"
using namespace std;

int ans;
map <char,int> m={{'T',9},{'J',10},{'Q',11},{'K',12},{'A',13}};

int consecutive(vector <string> &v)
{
	for(int i=1;i<5;i++)
		if(m[v[i][0]]!=m[v[i-1][0]]+1) return 0;
	return m[v[4][0]];
}

int same_suit(vector <string> &v)
{
	set <char> se;
	for(auto s:v) se.insert(s[1]);
	if(se.size()==1) return m[v[4][0]];
	else return 0;
}

int royal_flush(vector <string> &v)
{
	return consecutive(v) and v[0][0]=='T' and same_suit(v);
}

int straight_flush(vector <string> &v)
{
	if(consecutive(v) and same_suit(v)) return m[v[4][0]];
	else return 0;
}

int four_of_a_kind(vector <string> &v)
{
	if(m[v[0][0]]==m[v[3][0]]) return m[v[3][0]];
	else if(m[v[1][0]]==m[v[4][0]]) return m[v[4][0]];
	else return 0;
}

int full_house(vector <string> &v)
{
	if(m[v[0][0]]==m[v[1][0]] and m[v[2][0]]==m[v[4][0]]) return m[v[4][0]];
	if(m[v[0][0]]==m[v[2][0]] and m[v[3][0]]==m[v[4][0]]) return m[v[2][0]];
	else return 0;
}

int three_of_a_kind(vector <string> &v)
{
	for(int i=0;i<3;i++)
		if(m[v[i][0]]==m[v[i+2][0]]) return m[v[i+2][0]];
	return 0;
}

int two_pairs(vector <string> &v)
{
	if(v[0][0]==v[1][0])
	{
		if(v[2][0]==v[3][0]) return 200+m[v[3][0]];
		else if(v[3][0]==v[4][0]) return 200+m[v[4][0]];
		return 100+m[v[1][0]];
	}
	else if(v[1][0]==v[2][0])
	{
		if(v[3][0]==v[4][0]) return 200+m[v[4][0]];
		return 100+m[v[2][0]];
	}
	else if(v[2][0]==v[3][0]) return 100+m[v[3][0]];
	else if(v[3][0]==v[4][0]) return 100+m[v[4][0]];
	else return 0;
}

int get_rank(vector <string> &v)
{
	sort(v.begin(),v.end(),[](string a,string b){return m[a[0]]<m[b[0]];});
	if(royal_flush(v)) return INT_MAX;
	if(straight_flush(v)) return 900+straight_flush(v);
	if(four_of_a_kind(v)) return 800+four_of_a_kind(v);
	if(full_house(v)) return 700+full_house(v);
	if(same_suit(v)) return 600+same_suit(v);//flush
	if(consecutive(v)) return 500+consecutive(v);//straight
	if(three_of_a_kind(v)) return 400+three_of_a_kind(v);
	if(two_pairs(v)) return two_pairs(v);
	return 0;//draw
}

bool win(vector <string> &p1,vector <string> &p2)
{
	int r1=get_rank(p1),r2=get_rank(p2);
	if(r1!=r2) return r1>r2;
	for(int i=4;i>=0;i--)
		if(m[p1[i][0]]>m[p2[i][0]]) return true;
		else if(m[p1[i][0]]<m[p2[i][0]]) return false;
}

int main()
{
	for(char c='2';c<='9';c++) m[c]=c-'2'+1;
	for(int _=0;_<1000;_++)
	{
		string s;
		vector <string> p1,p2;
		for(int i=0;i<5;i++) cin>>s,p1.push_back(s);
		for(int i=0;i<5;i++) cin>>s,p2.push_back(s);
		if(win(p1,p2)) ans++;
	}
	cout<<ans;
}