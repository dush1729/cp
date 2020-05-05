// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/
class Solution {
public:
    int findComplement(int num) {
        int len = 32 - __builtin_clz(num);
        return num ^ ((1ll << len) - 1);
    }
};