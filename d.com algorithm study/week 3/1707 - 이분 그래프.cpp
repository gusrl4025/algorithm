#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cstring> // memset함수를 사용
using namespace std;

int k, v, e, from, to;
int check[20005];
vector<int> a[20005];

void dfs(int n, int num) {
	check[n] = num;
	int size = a[n].size();
	for (int i = 0; i < size; i++) {
		int x = a[n][i];
		if (check[x] == 0) dfs(x, 3 - num);
	}
}

bool isBipartite(int n) {
	for (int i = 1; i <= n; i++) {
		int size = a[i].size();
		for (int j = 0; j < size; j++) if (check[i] == check[a[i][j]]) return false;
	}
	return true;
}

int main() {
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &v, &e);

		//백터 a와 check배열의 데이터를 0으로 초기화시켜준다.
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= v; i++) check[i] = 0;

		for (int i = 0; i < e; i++) {
			scanf("%d%d", &from, &to);
			a[from].push_back(to);
			a[to].push_back(from);
		}

		// 독립된 그래프가 있을 수 있으므로 모든 정점에서 확인해준다.
		for (int i = 1; i <= v; i++) if (check[i] == 0) dfs(i, 1);

		if (isBipartite(v)) printf("YES\n");
		else printf("NO\n");
	}
}