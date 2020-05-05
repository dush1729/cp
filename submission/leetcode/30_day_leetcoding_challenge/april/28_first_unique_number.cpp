class FirstUnique {
public:
    map <int,int> m;
    queue <int> q;
    FirstUnique(vector<int>& a) {
        m.clear();
        while(not q.empty()) q.pop();
        for(auto i:a) {
            if(m.find(i) == m.end()) q.push(i);
            m[i]++;
        }
    }
    
    int showFirstUnique() {
        while(not q.empty() and m[q.front()] > 1) {
            q.pop();
        }
        return q.empty() ? -1 : q.front();
    }
    
    void add(int value) {
        if(m.find(value) == m.end()) q.push(value);
        m[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */