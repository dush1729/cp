#include "bits/stdc++.h"
using namespace std;

const int C = 26;

int m[C];

class Solution
{
public:
    bool canConvertString(string s, string t, int k)
    {
        if(s.size() != t.size()) return false;
        for(int i = 0; i < C; i++) m[i] = 0;

        int mx = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int diff = t[i] - s[i];
            if(diff == 0) continue;
            if(diff < 0) diff += 26;

            int val = 26 * m[diff] + diff;
            mx = max(mx, val);
            m[diff]++;
        }

        return mx <= k;
    }
};