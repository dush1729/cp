const int N = 300, MOD = 1e9 + 7;

int n, s, t, f;
int dp[N][N]; // fuel, city
vector <int> a;

int func(int fuel, int city)
{
    int &ans = dp[fuel][city];
    if(ans != -1) return ans;

    if(city == t) ans = 1;
    else ans = 0;
    for(int i = 0; i < n; i++)
        if(i != city and fuel >= abs(a[city] - a[i]))
            ans = (ans + func(fuel - abs(a[city] - a[i]), i)) % MOD;
    return ans;
}

// time O(n*n*fuel) | space O(n*fuel)
class Solution
{
public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        n = locations.size();
        a = locations;
        s = start;
        t = finish;
        f = fuel;

        for(int i = 0; i <= fuel; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = -1;

        return func(fuel, start);
    }
};