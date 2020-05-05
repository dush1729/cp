
// time O(n + m) | space O(n)
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.size(), m = shift.size(), d = 0;
        for(auto v: shift) {
            if(v[0] == 0) d += v[1];
            else d -= v[1];
        }
        
        // 5
        // 9 -> 4
        // 13 -> 3
        // 4l, 6r -> -2l -> -2+5 -> 3
        
        d %= n;
        if(d < 0) d += n;
        
        // abcde 2l
        // cdeab
        
        return s.substr(d) + s.substr(0, d);
    }
};