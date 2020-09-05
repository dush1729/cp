// time O(n) | space O(n)
class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &a)
    {
        vector <int> s = a;
        sort(s.begin(), s.end());
        if(a == s) return 0;

        int n = a.size();

        vector <pair <int, int>> r;
        r.push_back({a[n - 1], n - 1});
        for(int i = n - 2; i >= 0 and a[i] <= a[i + 1]; i--) r.push_back({a[i], i});
        reverse(r.begin(), r.end());

        int rptr = 0, ans = n - r.size();
        for(int i = 0; i < n; i++)
        {
            if(i == 0 or a[i] >= a[i - 1])
            {
                while(rptr < r.size() and r[rptr].first < a[i]) rptr++;

                if(rptr == r.size()) ans = min(ans, n - i - 1);
                else ans = min(ans, r[rptr].second - i - 1);
            }
            else break;
        }
        return ans;
    }
};