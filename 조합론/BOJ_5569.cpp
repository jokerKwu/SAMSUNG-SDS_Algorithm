#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 102
#define M 100000
/*
	방향 : 0 북 1 동
	변경 : 0 노변경 1 변경
*/
int visit[MAX][MAX][2][2];	// y x 방향 변경
int w, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> w >> h;
	for (int i = 0;i < w;i++) visit[h - 1][i][1][0] = 1;
	for (int i = 0;i < h;i++) visit[i][0][0][0] = 1;
	for (int i = h-2;i >= 0;i--) {
		for (int j = 1;j < w;j++) {
			// 북 변경x
			visit[i][j][0][0] = (visit[i + 1][j][0][0] + visit[i+1][j][0][1]) % M;
			// 북 변경o
			visit[i][j][0][1] = visit[i + 1][j][1][0];
			// 동 변경 x
			visit[i][j][1][0] = (visit[i][j - 1][1][0] + visit[i][j-1][1][1]) % M;
			//동 변경 o
			visit[i][j][1][1] = visit[i][j - 1][0][0];
		}
	}
	int answer = 0;
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < 2;j++) {
			answer += visit[0][w - 1][i][j];
		}
	}
	cout << answer % M << '\n';
	return 0;
}