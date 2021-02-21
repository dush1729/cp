vector<int> solve(vector<vector<int>>& points) {
    unordered_map <int, vector <int>> x, y;
    for(auto &v: points) {
        x[v[0]].push_back(v[1]);
        y[v[1]].push_back(v[0]);
    }
    for(auto &p: x) {
        sort(p.second.begin(), p.second.end());
    }
    for(auto &p: y) {
        sort(p.second.begin(), p.second.end());
    }

    vector <int> ans;
    for(auto &v: points) {
        int t = INT_MAX;

        auto i = upper_bound(x[v[0]].begin(), x[v[0]].end(), v[1]);
        if(i != x[v[0]].end()) {
            t = min(t, *i - v[1]);
        }
        i--;
        if(i != x[v[0]].begin()) {
            i--;
            t = min(t, v[1] - *i);
        }

        auto j = upper_bound(y[v[1]].begin(), y[v[1]].end(), v[0]);
        if(j != y[v[1]].end()) {
            t = min(t, *j - v[0]);
        }
        j--;
        if(j != y[v[1]].begin()) {
            j--;
            t = min(t, v[0] - *j);
        }


        ans.push_back(t);
    }
    return ans;
}
