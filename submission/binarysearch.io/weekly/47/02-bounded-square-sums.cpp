int solve(vector<int>& a, vector<int>& b, int lower, int upper) {
    auto sqsort = [&](vector <int> &a) {
        for(int &x: a) x *= x;
        sort(a.begin(), a.end());
    };
    sqsort(a);
    sqsort(b);

    auto f = [&](int s) {
        int i = b.size() - 1, ans = 0;
        for(int x: a) {
            while(i >= 0 && x + b[i] > s) i--;
            ans += i + 1;
        }
        return ans;
    };

    return f(upper) - f(lower - 1);
}
