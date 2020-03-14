#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int T, n;
int a[1000005];

int main() {
	scanf("%d", &T);
	for(int i = 0; i < T; i++) {
		scanf("%d", &n);
		a[i] = n;
	}
	sort(a, a + T);
	for (int i = 0; i < T; i++) printf("%d\n", a[i]);
}