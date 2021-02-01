vector<int> solve(string s) {
	int n = s.size();
	vector <int> f(n, 0);
	int b = 0, mx = 0;
	for(auto c: s) {
		if(c == '(') b++;
		else if(c == ')') b--;
		else {
			f[b]++;
		}
		mx = max(mx, b);
	}
	f.erase(f.begin());
	f.resize(mx);
	return f;
}
