#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int T, n;
long long dp[105];

long long bottom_up(int n) {
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	// 5��°���� �ݺ����� �����ϴ� ������ dp[0] = 0���� �ʱ�ȭ �Ǿ��ֱ� ������
	// dp[5] = dp[0] + dp[4]�� �����ϱ� �����̴�.
	for (int i = 5; i <= n; i++) dp[i] = dp[i - 5] + dp[i - 1];
	return dp[n];
}

long long top_down(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n == 3) return 1;
	if (n == 4) return 2;
	if (dp[n] > 0) return dp[n];
	return dp[n] = top_down(n - 5) + top_down(n - 1);
}

int main() {

	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);
		printf("%lld\n", bottom_up(n));
		//printf("%lld\n", top_down(n));
	}
	return 0;
}