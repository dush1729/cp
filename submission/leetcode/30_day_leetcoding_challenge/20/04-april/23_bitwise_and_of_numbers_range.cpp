class Solution {
public:
    // time O(logn) | space O(1)
    int rangeBitwiseAnd(int m, int n) {
        // 0010110001
        // 0010110101
        
        int ans = 0;
        for(int i = 30; i >= 0; i--) {
            int bit1 = m & (1<<i);
            int bit2 = n & (1<<i);
            if(bit1 != bit2) break;
            ans += bit1;
        }
        return ans;
    }
};