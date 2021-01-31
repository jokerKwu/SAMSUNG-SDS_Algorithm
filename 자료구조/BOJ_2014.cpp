#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k, n;
	cin >> k >> n;
	vector<int> prime;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		prime.push_back(num);
		pq.push(num);
	}
	
	ll top = 0;
	for (int i = 0; i < n; i++) {
		top = pq.top();
		pq.pop();
		for (int j = 0; j < k; j++) {
			ll value = top * prime[j];
			pq.push(value);
			if (top % prime[j] == 0)break;
		}
	}
	cout << top << '\n';

	return 0;
}