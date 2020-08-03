#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int getWinner(vector<int> &a, int k)
    {
        int mx = *max_element(begin(a), end(a));

        deque <int> dq;
        for(auto i : a) dq.push_back(i);

        int winner = dq.front(), wins = 0;
        while(1729)
        {
            int first = dq.front();
            dq.pop_front();
            if(first == mx) return first;

            int second = dq.front();
            dq.pop_front();

            if(first > second)
            {
                dq.push_front(first);
                dq.push_back(second);
                wins++;
            }
            else
            {
                dq.push_front(second);
                dq.push_back(first);
                winner = dq.front(), wins = 1;
            }
            if(wins == k or winner == mx) return winner;
        }
        return -1;
    }
};