#include "solution.hpp"
using namespace std;


class Solution {
	public:
	int solve(vector<vector<int>>& sales, vector<vector<int>>& buyers) {
		map <int, vector <int>> m;
		for(auto vec:buyers) m[vec[0]].push_back(vec[1]);

		sort(sales.begin(),sales.end());

		auto it=m.begin();
		multiset <int> ms;
		int ans=0;
		for(auto item:sales)
		{
			while(it!=m.end() and it->first<=item[0])
			{
				for(auto i:it->second) ms.insert(i);
				it++;
			}

			auto it2=ms.lower_bound(item[1]);
			if(it2!=ms.end()) ms.erase(it2),ans++;
		}
		return ans;
	}
};
