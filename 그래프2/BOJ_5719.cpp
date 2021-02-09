#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;
#define MAX 502
#define INF 987654321
int N, M, S, D;
typedef pair<int, int> pii;
int dist[MAX] = { INF, };
int edge[MAX][MAX] = { 0, };
void dijkstra() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,S });
	while (!pq.empty()) {
		int cv = pq.top().first;
		int cn = pq.top().second;
		pq.pop();
		if (dist[cn] != INF) continue;
		dist[cn] = cv;
		//다음 노드 
		for (int i = 0;i < N;i++) {
			if (edge[cn][i] == -1) continue;
			if (dist[i] != INF) continue;
			pq.push({cv + edge[cn][i], i});
		}
	}
}
//bfs 로 역추적 해가지고 간선을 지운다.
void eraseEdge() {
	queue<int> q;
	q.push(D);
	while (!q.empty()) {
		int cx = q.front();
		q.pop();
		for (int i = 0;i < N;i++) {
			if (dist[cx] == edge[i][cx] + dist[i] && edge[i][cx] != -1) {
				edge[i][cx] = -1;
				q.push(i);
			}
		}
	}
	for (int i = 0;i < N;i++) dist[i] = INF;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		for (int i = 0;i < N;i++) {
			dist[i] = INF;
			for (int j = 0;j < N;j++) {
				edge[i][j] = -1;
			}
		}
		cin >> S >> D;
		for (int i = 0;i < M;i++) {
			int a, b, c;
			cin >> a >> b >> c;
			edge[a][b] = c;
		}
		dijkstra();
		eraseEdge();
		dijkstra();
		if (dist[D] == INF) cout << -1 << '\n';
		else cout << dist[D] << '\n';
	}
	return 0;
}

/*

7 9
0 6
0 1 1
0 2 1
0 3 2
0 4 3
1 5 2
2 6 4
3 6 2
4 6 4
5 6 1
4 6
0 2
0 1 1
1 2 1
1 3 1
3 2 1
2 0 3
3 0 2
6 8
0 1
0 1 1
0 2 2
0 3 3
2 5 3
3 4 2
4 1 1
5 1 1
3 0 1
0 0
*/