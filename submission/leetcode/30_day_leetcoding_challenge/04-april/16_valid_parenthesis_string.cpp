// time O(n) | space O(n)
class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0;
        deque <int> dq;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') open++;
            else if(s[i]==')') close++;
            else dq.push_back(i);
            
            while(open<close) {
                if(dq.empty()) return false;
                s[dq.front()]='(';
                dq.pop_front();
                open++;
            }
        }
        
        while(open<close) {
            if(dq.empty()) return false;
            s[dq.front()]='(';
            dq.pop_front();
            open++;
        }
        
        // (()*
        while(close<open) {
            if(dq.empty()) return false;
            s[dq.back()]=')';
            dq.pop_back();
            close++;
        }
        
        int balance = 0;
        for(auto c:s) {
            if(c=='(') balance++;
            else if(c==')') balance--;
            if(balance<0) return false;
        }
        return balance == 0;
    }
};