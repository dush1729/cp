/*
Description
compress the given list to list containing values from
1 to number_of_distinct_values

Input
vector of ints

Return
number_of_distinct_values

Problems
https://codeforces.com/contest/61/problem/E
https://binarysearch.com/problems/Longest-Repeating-Sublist-After-K-Updates
*/

int compress(vector <int> &v) {
	if(v.empty()) return 0;
	vector <int> s = v;
	sort(s.begin(), s.end());
	s.resize(unique(s.begin(), s.end()) - s.begin());

	int mx = 1;
	for(int &x: v) {
		x = lower_bound(s.begin(), s.end(), x) - s.begin() + 1;
		mx = max(mx, x);
	}
	return mx;
}