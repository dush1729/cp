// time O(n) | space O(n)
class Solution {
public:
    int findMaxLength(vector<int>& a) {
        int n=a.size();
        for(int i=0;i<n;i++)
            if(a[i]==0) a[i]=-1;
        
        map <int,int> m;
        int s=0,ans=0;
        
        m[0]=-1;
        for(int i=0;i<a.size();i++)
        {
            s+=a[i];
            if(m.find(s)!=m.end()) ans=max(ans,i-m[s]);
            else m[s]=i;
        }
        return ans;
    }
};