#include "solution.hpp"
using namespace std;


class Solution {
    public:
    bool solve(vector<int>& nums) {
        // Write your code here
        map <int,int> m;
        for(auto i:nums) m[i]++;
        for(auto i:m)
            if(i.second%2==1) return false;
        return true;
    }
};
