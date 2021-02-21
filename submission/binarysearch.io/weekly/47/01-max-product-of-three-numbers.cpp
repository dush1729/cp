int solve(vector<int>& a) {
    int n = a.size();
    if(n < 3) return 0;
    sort(a.begin(), a.end());

    return max({a[n - 1] * a[n - 2] * a[n - 3], a[n - 1] * a[0] * a[1]});
}
