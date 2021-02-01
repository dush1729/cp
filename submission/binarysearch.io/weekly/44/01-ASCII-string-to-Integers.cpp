int solve(string s) {
	int num = 0, ans = 0;
	s += "A";
	for(char c: s) {
		if(c >= '0' && c <= '9') {
			num = num * 10 + c - '0';
		} else {
			ans += num;
			num = 0;
		}
	}
	return ans;
}
