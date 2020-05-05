// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/
class Solution {
public:
    int numJewelsInStones(string a, string b) {
        sort(a.begin(),a.end());
        int ans=0;
        for(auto c:b)
            if(binary_search(a.begin(),a.end(),c)) ans++;
        return ans;
    }
};