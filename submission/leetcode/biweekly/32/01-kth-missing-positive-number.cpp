#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &a, int k)
    {
        for(int i = 1;; i++)
        {
            if(not binary_search(a.begin(), a.end(), i))
            {
                if(k == 1) return i;
                k--;
            }
        }
        return -1;
    }
};