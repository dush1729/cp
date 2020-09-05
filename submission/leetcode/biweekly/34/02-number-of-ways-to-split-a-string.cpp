const int N = 1e5 + 20, MOD = 1e9 + 7;

// time O(n) | space O(1)
class Solution
{
public:
    int numWays(string a)
    {
        int n = a.size(), cnt = count(a.begin(), a.end(), '1');
        if(cnt % 3) return 0;

        if(cnt == 0) return (1ll * (n - 1) * (n - 2) / 2) % MOD;

        int req = cnt / 3;
        while(req)
        {
            if(a.back() == '1') req--;
            a.pop_back();
        }

        int r = 1;
        while(a.back() == '0') r++, a.pop_back();

        reverse(a.begin(), a.end());

        req = cnt / 3;
        while(req)
        {
            if(a.back() == '1') req--;
            a.pop_back();
        }

        int l = 1;
        while(a.back() == '0') l++, a.pop_back();

        return (1ll * l * r) % MOD;
    }
};