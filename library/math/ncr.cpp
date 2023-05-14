/*
Problems
https://codeforces.com/contest/560/problem/E
*/

const int MOD = 1e9 + 7;
struct mi {
 	int v; explicit operator int() const { return v; } 
	mi():v(0) {}
	mi(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pwr(mi a, ll p) { return p==0?1:pwr(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pwr(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
mi operator/=(mi &a, mi b) { return a = a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

const int N = 2e5 + 20;
mi f[N], finv[N];
void precompute() {
	f[0] = 1;
	for(int i = 1; i < N; i++) f[i] = f[i - 1] * i;
	finv[N - 1] = 1 / f[N - 1];
	for(int i = N - 2; i >= 0; i--) finv[i] = finv[i + 1] * (i + 1);
}
mi choose(int n, int r) {
	if(r < 0 or r > n) return 0;
	return f[n] * finv[r] * finv[n - r];
}