#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 502
#define INF 987654321
int N, M;
typedef long long ll;
typedef pair<int, ll> pii;
vector<pii> edge[MAX];
ll dist[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0;i <= N;i++) dist[i] = INF;
	dist[1] = 0;
	for (int i = 0;i < M;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
	}
	for (int i = 0;i < N-1;i++) {
		for (int j = 1;j <= N;j++) {
			for (auto& p : edge[j]) {
				int nextNode = p.first;
				ll nextDist = p.second + dist[j];
				if (dist[j] != INF && dist[nextNode] > nextDist) {
					dist[nextNode] = nextDist;
				}
			}
		}
	}
	//음수 사이클 발생하는지 체크
	bool minusCycle = false;
	for (int j = 1;j <= N;j++) {
		for (auto& p : edge[j]) {
			int nextNode = p.first;
			ll nextDist = p.second + dist[j];
			if (dist[j] != INF && dist[nextNode] > nextDist) {
				minusCycle = true;
				break;
			}
		}
	}
	if (minusCycle) cout << -1 << '\n';
	else {
		for (int i = 2;i <= N;i++) {
			if (dist[i] != INF) cout << dist[i] << '\n';
			else cout << -1<< '\n';
		}
	}

	return 0;
}