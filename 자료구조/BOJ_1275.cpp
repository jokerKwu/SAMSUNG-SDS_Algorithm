#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100002
typedef long long ll;

ll arr[MAX];
ll tree[MAX * 4];
int N, Q;
ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(int start, int end, int node, int index, ll diff) {
	//범위를 벗어난 경우
	if (index < start || end < index) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid + 1, end, node * 2 + 1, index, diff);
}
ll sum(int start, int end, int node, int left, int right) {
	// 범위를 벗어난 경우
	if (right < start || end < left) return 0;
	//범위 안에 있는 경우
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	for (int i =1;i <= N;i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	init(1, N+1, 1);
	for (int i = 0;i < Q;i++) {
		int x, y, a;
		ll b;
		cin >> x >> y >> a >> b;
		if (x > y) {
			swap(x, y);
		}
		ll diff = b - arr[a];
		arr[a] = b;
		cout << sum(1, N+1, 1, x, y) << '\n';
		update(1, N+1, 1, a, diff);
	}


	return 0;
}