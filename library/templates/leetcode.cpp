#include "bits/stdc++.h"
using namespace std;
#define ll long long



class Solution {
public:
	int maxSumDivThree() {return 0;
	}
};

int testcase = 0;
void test(int expected) {
	auto output = Solution().maxSumDivThree();
	if(expected != output) {
		cout << "Failed at test " << ++testcase << endl;
		cout << "expected : " << expected << endl;
		cout << "output   : " << output << endl;
		exit(0);
	} else {
		cout << "Test " << ++testcase << " passed." << endl;
	}
}

#ifdef DUSH1729
int main(){
	test(0);
	cout << "All tests passed successfully!" << endl;
}
#endif