#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;

class Solution
{
public:
    int numOfSubarrays(vector<int> &a)
    {
        int odd = 0, even = 1;
        int sum = 0;

        int ans = 0;
        for(auto i : a)
        {
            sum += i;
            if(sum % 2 == 0)
            {
                even++;
                ans += odd;
            }
            else
            {
                odd++;
                ans += even;
            }
            ans %= MOD;
        }
        return ans;
    }
};