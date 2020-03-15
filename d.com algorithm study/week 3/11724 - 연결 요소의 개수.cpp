#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, from, to, cnt;
vector<int> a[1005];
bool check[500005];

void dfs(int n) {
	check[n] = true;
	for (int j = 0; j < a[n].size(); j++) {
		int x = a[n][j];
		if (check[x] == false) dfs(x);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &from, &to);
		a[from].push_back(to);
		a[to].push_back(from);
	}

	//dfs로 첫번째 정점부터 dfs를 시작한다.
	//dfs가 한번 끝나면 한 파티션 안의 정점의 check[i]는 true가 된다.
	//그래서 차례대로 check[i]의 false 유무를 확인하여
	//false인 i를 다시 dfs를 통해 그 파티션 안의 정점을 확인해준다.
	//그래서 dfs가 실행될 때마다 파티션이 하나씩 늘어나므로 cnt를 하나씩 늘려준다음 출력한다.
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt++;
		}
	}

	printf("%d", cnt);
}