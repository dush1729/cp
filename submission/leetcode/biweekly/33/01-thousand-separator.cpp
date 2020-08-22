#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string thousandSeparator(int n)
    {
        string a = to_string(n), ans;

        int cnt = 0;
        for(int i = a.size() - 1; i >= 0; i--)
        {
            cnt++;
            ans += a[i];
            if(cnt % 3 == 0) ans += ".";
        }
        if(ans.back() == '.') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*
time O(logn)
space O(logn)
*/