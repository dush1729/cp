#include "bits/stdc++.h"
using namespace std;

const int MAX = 1e6 + 20;

int lp[MAX];
vector <int> prime;

void preprocess() {
	// find least prime divisor for all from [1, MAX - 1]
	for(int i = 2; i * i < MAX; i++)
		if(!lp[i])
			for(int j = i * i; j < MAX; j += i)
				if(!lp[j]) lp[j] = i;
	for(int i = 2; i < MAX; i++) {
		if(!lp[i]) lp[i] = i;
		if(lp[i] == i) prime.push_back(i);
	}
	lp[1] = 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
}