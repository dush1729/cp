#include "solution.hpp"
using namespace std;


class Solution {
	public:
	int solve(vector<int>& a) {
		int n=a.size();
		set <int> s;
		for(auto i:a) s.insert(i);
		return (n-s.size()+1)/2;
	}
};
