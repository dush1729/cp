// time O(n) | space O(n)
string f(string a)
{
    string s="";
    for(auto i:a)
    {
        if(i=='#')
        {
            if(s.size()>0) s.pop_back();
        }
        else
        {
            s+=i;
        }
    }
    return s;
}

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return f(S)==f(T);
    }
};