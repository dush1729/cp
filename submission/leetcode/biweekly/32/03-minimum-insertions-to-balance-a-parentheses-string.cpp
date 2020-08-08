#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minInsertions(string a)
    {
        int open = 0, ans = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] == '(') open++;
            else
            {
                if(open == 0) open++, ans++;
                if(i + 1 < a.size() and a[i + 1] == ')') i++;
                else ans++;
                open--;
            }
        }

        return ans + open * 2;
    }
};