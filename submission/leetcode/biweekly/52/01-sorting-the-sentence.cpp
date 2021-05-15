class Solution {
public:
	string sortSentence(string s) {
		vector <pair <int, string>> v;
		s += " ";
		string str;
		for(char c: s) {
			if(c == ' ') {
				int d = str.back() - '0';
				str.pop_back();
				v.push_back({d, str});
				str = "";
			} else {
				str += c;
			}
		}

		sort(v.begin(), v.end());
		string ans;
		for(auto [_, s]: v) ans += s + " ";
        ans.pop_back();
		return ans;
	}
};