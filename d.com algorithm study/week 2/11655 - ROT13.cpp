#include<iostream>
#include<string>
using namespace std;

int n;
string S;

string ROT13(string S) {
	for (int i = 0; i < S.size(); i++) {
		if (S[i] >= 'a' && S[i] <= 'z') S[i] = 'a' + ((S[i] - 'a') + 13) % 26;
		if (S[i] >= 'A' && S[i] <= 'Z') S[i] = 'A' + ((S[i] - 'A') + 13) % 26;
	}
	return S;
}

int main() {
	getline(cin, S);
	cout << ROT13(S);
}