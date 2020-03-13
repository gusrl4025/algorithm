#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int n, m, from, to;
vector<int> a[2005];
int check[2005];

bool dfs(int n, int cnt) {
	//cnt가 4라는 것은 정점 5개가 연결되어있다는 뜻이므로 true를 반환한다.
	if (cnt == 4) return true;
	//정점 n을 지났다는 뜻이므로 true로 해둔다.
	check[n] = true;
	//n에서 연결되어 있는 정점들을 하나씩 살펴가면서 
	for (int i = 0; i < a[n].size(); i++) {
		int x = a[n][i];
		//정점x를 지나지않았으면
		if (check[x] == false) {
			//정점x에서 다시 검색하고 cnt를 1 늘린다.
			if (dfs(x, cnt + 1)) return true;
		}
	}
	//탐색이 끝난 뒤 다시 false로 초기화해준다.
	check[n] = false;
	//cnt가 4가 되지 않으면 false를 반환한다.
	return false;
}
int main() {

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &from, &to);
		a[from].push_back(to);
		a[to].push_back(from);
	}

	//정점0이 시작점 0일 때부터 n-1일 때까지 탐색을 해 정점 5개가 연결되어있으면 1를 출력 아니면 0을 출력한다.   
	for (int i = 0; i < n; i++) {
		if (dfs(i, 0) == true) {
			printf("1");
			return 0;
		}
	}
	printf("0");
}