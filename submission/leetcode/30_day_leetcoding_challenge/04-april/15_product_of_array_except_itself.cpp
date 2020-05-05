// time O(n) | space O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector <int> l = a, r = a;
        for(int i = 1; i < n; i++) l[i] = l[i-1] * a[i];
        for(int i = n - 2; i >= 0 ; i--) r[i] = r[i+1] * a[i];
        
        vector <int> ans;
        for(int i = 0; i < n; i++)
        {
            int p = 1;
            if(i > 0) p *= l[i-1];
            if(i + 1 < n) p *= r[i+1];
            ans.push_back(p);
        }
        return ans;
    }
};