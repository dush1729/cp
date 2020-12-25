/*
Description
return random number from range l to r

Input
ints l and r are optional
default values of l and r from 0 to datatype maximum value

Return
random number from range l to r

Problems
https://codeforces.com/contest/1200/problem/E
*/

int get_rand(int l = 0, int r = INT_MAX) {
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution <int> distribution(l, r);
	return distribution(rng);
}

long long get_randll(long long l = 0, long long r = LLONG_MAX) {
	static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution <long long> distribution(l, r);
	return distribution(rng);
}