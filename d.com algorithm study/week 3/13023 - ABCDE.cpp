#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int n, m, from, to;
vector<int> a[2005];
int check[2005];

bool dfs(int n, int cnt) {
	//cnt�� 4��� ���� ���� 5���� ����Ǿ��ִٴ� ���̹Ƿ� true�� ��ȯ�Ѵ�.
	if (cnt == 4) return true;
	//���� n�� �����ٴ� ���̹Ƿ� true�� �صд�.
	check[n] = true;
	//n���� ����Ǿ� �ִ� �������� �ϳ��� ���찡�鼭 
	for (int i = 0; i < a[n].size(); i++) {
		int x = a[n][i];
		//����x�� �������ʾ�����
		if (check[x] == false) {
			//����x���� �ٽ� �˻��ϰ� cnt�� 1 �ø���.
			if (dfs(x, cnt + 1)) return true;
		}
	}
	//Ž���� ���� �� �ٽ� false�� �ʱ�ȭ���ش�.
	check[n] = false;
	//cnt�� 4�� ���� ������ false�� ��ȯ�Ѵ�.
	return false;
}
int main() {

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &from, &to);
		a[from].push_back(to);
		a[to].push_back(from);
	}

	//����0�� ������ 0�� ������ n-1�� ������ Ž���� �� ���� 5���� ����Ǿ������� 1�� ��� �ƴϸ� 0�� ����Ѵ�.   
	for (int i = 0; i < n; i++) {
		if (dfs(i, 0) == true) {
			printf("1");
			return 0;
		}
	}
	printf("0");
}