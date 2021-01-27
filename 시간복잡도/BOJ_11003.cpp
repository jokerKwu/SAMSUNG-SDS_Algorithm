#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;
/*
12 3
1 5 2 3 6 2 3 7 3 5 2 6

1 1 1 2 2 2 2 2 3 3 2 2

*/
typedef pair<int, int> pii;

deque<pii> dq;	//ÀÎµ¦½º °ª
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	for (int i = 0;i < N;i++) {
		int num;
		cin >> num;
		if (dq.size() == 0) {
			cout << num << ' ';
			dq.push_back(make_pair(i, num));
		}
		else {
			while (dq.size() != 0 && dq.front().first < (i - (L - 1)))
				dq.pop_front();
			while (dq.size() != 0 && dq.back().second > num) {
				dq.pop_back();
			}
			dq.push_back(make_pair(i, num));
			cout << dq.front().second << ' ';
		}
	}

	return 0;
}