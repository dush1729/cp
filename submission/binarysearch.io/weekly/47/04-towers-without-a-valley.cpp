int solve(vector<int>& a) {
    int n = a.size();

    stack <int> s;
    vector <int> next_small(n, n), r(n + 1);
    for(int i = n - 1; i >= 0; i--) {
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(!s.empty()) next_small[i] = s.top();
        r[i] = (next_small[i] - i) * a[i] + r[next_small[i]];
        s.push(i);
    }

    s = stack<int>();
    vector <int> prev_small(n, -1), l(n);
    for(int i = 0; i < n; i++) {
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(!s.empty()) prev_small[i] = s.top();
        if(prev_small[i] == -1) l[i] = (i + 1) * a[i];
        else l[i] = (i - prev_small[i]) * a[i] + l[prev_small[i]];
        s.push(i);
    }

    int ans = r[0];
    for(int i = 0; i < n; i++) {
        ans = max(ans, l[i] + r[i] - a[i]);
    }

    return ans;
}
