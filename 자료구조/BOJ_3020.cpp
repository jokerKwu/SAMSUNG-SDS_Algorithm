#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 500001
int N, H;
int answer = 200001, cnt;
int top[MAX / 2], bottom[MAX / 2];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> H;
	for (int i = 0; i < (N/2); i++) {
		cin >> bottom[i] >> top[i];
	}
	sort(bottom, bottom + (N / 2));
	sort(top, top + (N / 2));
	for (int i = 1; i <= H; i++) {
		int tmp = (N / 2) - (lower_bound(bottom, bottom + (N / 2), i) - bottom);
		tmp += (N / 2) - (upper_bound(top, top + (N / 2), H - i) - top);
		if (tmp < answer) {
			cnt = 1;
			answer = tmp;
		}
		else if (tmp == answer) {
			cnt += 1;
		}
	}
	cout << answer << ' ' << cnt << '\n';
	
	return 0;
}