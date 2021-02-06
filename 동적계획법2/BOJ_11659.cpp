#include<iostream>
using namespace std;
int arr[100002];
long long sum[100002];
int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';
	}
}