/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    // time O(n + m) | space O(1)
    int leftMostColumnWithOne(BinaryMatrix &f) {
        vector <int> v = f.dimensions();
        int n = v[0], m = v[1];
        int ans = m - 1;
        for(int i = 0; i < n; i++) {
            while(ans >=0 and f.get(i, ans) == 1) ans--;
        }
        return ans == m - 1 ? -1 : ans + 1;
    }
};