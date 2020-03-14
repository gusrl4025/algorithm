#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m, v, from, to;
vector<int> a[1005];
queue<int> q;
int check[10005];

void dfs(int v) {
    printf("%d ", v);
    check[v] = true;
    // �ڽ� �������� �� ��ģ��.
    for (int i = 0; i < a[v].size(); i++) {
        int x = a[v][i];
        // ��� ��� �İ����.
        if (check[x] == false) dfs(x);
    }
}
         
void bfs(int v) {
    check[v] = true;
    // �������� queue�� �ִ´�.
    q.push(v);
    while (!q.empty()) {
        // ����� �������� �̵��Ѵ�.
        int x = q.front();
        printf("%d ", x);
        // ������ pop��Ų��.
        q.pop();
        // ������ ����� �������� queue�� �ִ´�.
        for (int i = 0; i < a[x].size(); i++) {
            // ���� ���뺰�� ���δ�.
            int z = a[x][i];
            if (check[z] == false) {
                check[z] = true;
                q.push(z);
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &v);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &from, &to);
        a[from].push_back(to);
        a[to].push_back(from);
    }
    // sort�� ���� ���� �ڽ��̸� ũ�������� ��µǰ� �Ѵ�.
    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }

    dfs(v);
    printf("\n");
    // check �迭�� 0���� �ʱ�ȭ���ش�.
    for (int i = 1; i <= n; i++) check[i] = 0;
    bfs(v);
}