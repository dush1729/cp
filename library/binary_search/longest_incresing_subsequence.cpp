int lis(vector <int> a) {
	vector <int> v;
	for(const int &x: a) {
		//lower_bound for strictly
		int i = upper_bound(v.begin(), v.end(), x) - v.begin();
		if(i == v.size()) v.push_back(x);
		else v[i] = x;
	}
	return v.size();
}

int lds(vector <int> a) {
	reverse(a.begin(), a.end());
	return lis(a);
}