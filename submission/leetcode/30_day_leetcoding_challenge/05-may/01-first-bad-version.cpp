// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo=1,hi=n,ans=1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(isBadVersion(mid)) hi=mid-1,ans=mid;
            else lo=mid+1;
        }
        return ans;
    }
};