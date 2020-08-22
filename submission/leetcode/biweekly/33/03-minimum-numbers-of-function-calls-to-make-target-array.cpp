#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &a, int steps = 0)
    {
        int mx = *max_element(a.begin(), a.end());
        if(mx == 0) return steps;

        for(auto &i : a)
            if(i % 2) i--, steps++;

        mx = *max_element(a.begin(), a.end());
        if(mx)
        {
            for(auto &i : a) i /= 2;
            steps++;
        }
        return minOperations(a, steps);
    }
};
/*
time O(nlog(max_value))
space O(1)
*/