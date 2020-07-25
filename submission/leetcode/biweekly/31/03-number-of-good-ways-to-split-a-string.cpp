#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 20;

int l[N], r[N];

class Solution
{
public:
    int numSplits(string a)
    {
        int n = a.size();

        set <char> s;
        for(int i = 0; i < n; i++)
        {
            s.insert(a[i]);
            l[i] = s.size();
        }

        s.clear();
        for(int i = n - 1; i >= 0; i--)
        {
            s.insert(a[i]);
            r[i] = s.size();
        }

        int ans = 0;
        for(int i = 0; i + 1 < n; i++)
            if(l[i] == r[i + 1]) ans++;
        return ans;
    }
};