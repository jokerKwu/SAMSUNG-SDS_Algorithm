#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	vector<pll> jewelry;
	vector<ll> bags;
	priority_queue<ll> pq;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;
		jewelry.push_back({ m,v });
	}
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		bags.push_back(num);
	}
	ll res = 0;
	sort(jewelry.begin(), jewelry.end());
	sort(bags.begin(), bags.end());
	
	int idx = 0;
	for (int i = 0; i < K; i++) {
		//현재 가방 무게에서 넣을 수 있는 보석을 다 넣는다.
		while (idx < N && bags[i] >= jewelry[idx].first ) {
			pq.push(jewelry[idx++].second);
		}
		if (!pq.empty()) {
			res += pq.top();
			pq.pop();
		}
	}	
	cout << res << '\n';

	return 0;
}