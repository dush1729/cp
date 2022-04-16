#define ll long long

vector <int> d = {20, 50, 100, 200, 500};

class ATM {
public:
	vector <ll> a;
	ATM() {
		a.resize(5);
	}
	
	void deposit(vector<int> banknotesCount) {
		for(int i = 0; i < 5; i++) a[i] += banknotesCount[i];
	}
	
	vector<int> withdraw(int amount) {
		vector <int> res(5), vec(5);
		for(int i = 4; i >= 0; i--) {
			ll k = min(a[i], 1ll * amount / d[i]);
			res[i] = k;
			a[i] -= k, vec[i] = k;
			amount -= k * d[i];
		}
		if(amount) {
			res = {-1};
			for(int i = 0; i < 5; i++) a[i] += vec[i];
		}
		return res;
	}
};