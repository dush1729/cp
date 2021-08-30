#include "bits/stdc++.h"
using namespace std;
#define ll long long
const int areTests = 1;

string VOWELS = "AEIOU", CONSONANTS;

void run_test(int testcase) {
	string a;
	cin >> a;

	unordered_map <char, int> frequency;
	for(char &c: a) {
		frequency[c]++;
	}

	int max_vowel = 0, total_vowels = 0;
	for(char &c: VOWELS) {
		int f = frequency[c];
		max_vowel = max(max_vowel, f);
		total_vowels += f;
	}

	int max_consonant = 0, total_consonants = 0;
	for(char &c: CONSONANTS) {
		int f = frequency[c];
		max_consonant = max(max_consonant, f);
		total_consonants += f;
	}

	int toVowels = 2 * (total_vowels - max_vowel) + total_consonants;
	int toConsonants = 2 * (total_consonants - max_consonant) + total_vowels;

	cout << "Case #" << testcase << ": ";
	cout << min(toVowels, toConsonants) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	#ifndef DUSH1729
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);

	for(char c = 'A'; c <= 'Z'; c++) {
		if(VOWELS.find(c) == string::npos) CONSONANTS += c;
	}

	int t = 1;
	if(areTests) cin >> t;
	for(int i = 1; i <= t; i++) {
		run_test(i);
	}
}