#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int T, n;
int arr[105];

int bottom_up(int n) {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	for (int i = 5; i < n; i++) dp[n] = dp[n - 4] + dp[n - 1];
	return dp[n];
}

int top_down(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n == 3) return 1;
	if (n == 4) return 2;
	if (dp[n] > 0) return dp[n];
	return dp[n] = top_down(n - 4) + top_down(n - 1);
}

int main() {

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		printf("%d", bottom_up(n));
		//printf("%d", top_down(n));
	}
	return 0;
}