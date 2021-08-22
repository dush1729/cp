// find least prime divisor for all values in [1, MAX - 1]
// size of prime can be reduced to primepi(MAX)

const int MAX = 1e6 + 2;
int lp[MAX], prime[MAX], prime_cnt; 
void sieve_linear() {
	for(int i = 2; i < MAX; i++) {
		if(lp[i] == 0) {
			lp[i] = i;
			prime[prime_cnt++] = i;
		}
		for(int j = 0; j < prime_cnt; j++) {
			int x = prime[j], m = i * x;
			if(x <= lp[i] && m < MAX) lp[m] = x;
			else break;
		}
	}
}

// if you only require lp, this reduces memory by half since prime list not required
void sieve_nloglogn() {
	for(int i = 2; i * i < MAX; i++)
		if(!lp[i])
			for(int j = i * i; j < MAX; j += i)
				if(!lp[j]) lp[j] = i;
	for(int i = 2; i < MAX; i++) {
		if(!lp[i]) lp[i] = i;
		if(lp[i] == i) prime[prime_cnt++] = i;
	}
}