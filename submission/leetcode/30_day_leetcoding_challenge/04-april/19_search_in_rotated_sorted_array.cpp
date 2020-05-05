int bs(vector <int> &a, int l, int r, int x)
{
    int lo = l, hi = r;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(a[mid] == x) return mid;
        else if(a[mid] < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

class Solution {
public:
    // time O(logn) | space O(1)
    int search(vector<int>& a, int target) {
        if(a.empty()) return -1;
        
        int n = a.size();
        int lo = 0, hi = n - 1, idx;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(a[mid] >= a[0]) lo = mid + 1;
            else hi = mid - 1, idx = mid;
        }
        
        if(idx == 0) {
            return bs(a, 0, n - 1, target);
        }
        else if(target < a[0]) {
            return bs(a, idx, n - 1, target);
        } else {
            return bs(a, 0, idx - 1, target);
        }
    }
};