/*
https://codeforces.com/contest/61/problem/E
https://binarysearch.com/problems/Longest-Repeating-Sublist-After-K-Updates
*/

void compress(vector <int> &v)
{
	vector <int> s=v;
	sort(s.begin(),s.end());

	int j=1;
	map <int,int> m;
	for(auto i:s) m[i]=j++;

	for(auto &i:v) i=m[i];
}