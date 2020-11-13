/*
https://codeforces.com/contest/61/problem/E
https://binarysearch.com/problems/Longest-Repeating-Sublist-After-K-Updates
*/

void compress(vector <int> &v)
{
	if(v.empty()) return;
	vector <int> s=v;
	sort(s.begin(),s.end());

	int j=1;
	unordered_map <int,int> m;
	m[s[0]]=j++;
	for(int i=1;i<s.size();i++)
		if(s[i]!=s[i-1]) m[s[i]]=j++;

	for(auto &i:v) i=m[i];
}