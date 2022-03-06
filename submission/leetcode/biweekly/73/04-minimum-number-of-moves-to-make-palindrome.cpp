class Solution {
public:
    int minMovesToMakePalindrome(string a) {
        int n = a.size(), ans = 0;

        for(int l = 0, r = n - 1; l < r; ) {
            int idx = l;
            while(idx < r && a[idx] != a[r]) idx++;

            if(idx == r) {
                swap(a[r], a[r - 1]);
                ans++;
                continue;
            }

            while(idx > l) {
                swap(a[idx], a[idx - 1]);
                idx--;
                ans++;
            }
            l++, r--;
        }
        return ans;
    }
};