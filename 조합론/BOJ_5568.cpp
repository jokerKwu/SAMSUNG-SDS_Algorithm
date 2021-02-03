#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
set<string> s;
vector<string> strs;
int N, K;
bool visit[12];
void dfs(int cnt, string tmp) {
	if (cnt == K) {
		s.insert(tmp);
		return;
	}
	for (int i = 0;i < N;i++) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(cnt + 1, tmp + strs[i]);
			visit[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0;i < N;i++) {
		string str;
		cin >> str;
		strs.push_back(str);
	}
	dfs(0,"");
	cout << s.size() << '\n';
	return 0;
}
/*
4
2
1
2
12
1
상근이는 11, 12, 21, 112, 121, 122, 212를 만들 수 있다.
*/