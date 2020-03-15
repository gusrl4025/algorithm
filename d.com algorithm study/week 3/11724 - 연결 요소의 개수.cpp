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

	//dfs�� ù��° �������� dfs�� �����Ѵ�.
	//dfs�� �ѹ� ������ �� ��Ƽ�� ���� ������ check[i]�� true�� �ȴ�.
	//�׷��� ���ʴ�� check[i]�� false ������ Ȯ���Ͽ�
	//false�� i�� �ٽ� dfs�� ���� �� ��Ƽ�� ���� ������ Ȯ�����ش�.
	//�׷��� dfs�� ����� ������ ��Ƽ���� �ϳ��� �þ�Ƿ� cnt�� �ϳ��� �÷��ش��� ����Ѵ�.
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt++;
		}
	}

	printf("%d", cnt);
}