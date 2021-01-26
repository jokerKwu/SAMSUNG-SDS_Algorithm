#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 52
char board[MAX][MAX];
bool visit[MAX][MAX];
int dp[MAX][MAX];
int m_xy[4][2] = { {0,1} ,{1,0} , { -1, 0}, {0, -1} };
int N, M;
bool rangeCheck(int x, int y) {
	if ((x < 0 || x >= M) || (y < 0 || y >= N)) return true;
	return false;
}
int dfs(int x, int y) {

	int cur_num = board[y][x] - '0';
	if (rangeCheck(x, y) == true || board[y][x] == 'H') return 0;
	if (visit[y][x]) { cout << -1 << endl; exit(0); }
	if (dp[y][x] != 0) return dp[y][x];
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
		dp[y][x] = max(dp[y][x], dfs(x + (cur_num * m_xy[i][0]), y + (cur_num * m_xy[i][1])) + 1);
	visit[y][x] = false;
	return dp[y][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	cout << dfs(0, 0) << '\n';
	return 0;
}