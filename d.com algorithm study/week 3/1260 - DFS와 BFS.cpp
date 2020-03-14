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
    // 자식 정점들을 다 거친다.
    for (int i = 0; i < a[v].size(); i++) {
        int x = a[v][i];
        // 계속 깊게 파고들어간다.
        if (check[x] == false) dfs(x);
    }
}
         
void bfs(int v) {
    check[v] = true;
    // 시작점을 queue에 넣는다.
    q.push(v);
    while (!q.empty()) {
        // 연결된 정점으로 이동한다.
        int x = q.front();
        printf("%d ", x);
        // 정점을 pop시킨다.
        q.pop();
        // 나머지 연결된 정점들을 queue에 넣는다.
        for (int i = 0; i < a[x].size(); i++) {
            // 같은 세대별로 쌓인다.
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
    // sort를 해줘 같은 자식이면 크기순서대로 출력되게 한다.
    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }

    dfs(v);
    printf("\n");
    // check 배열을 0으로 초기화해준다.
    for (int i = 1; i <= n; i++) check[i] = 0;
    bfs(v);
}