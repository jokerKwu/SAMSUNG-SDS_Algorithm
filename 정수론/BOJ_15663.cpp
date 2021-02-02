#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<int> arr;
vector<int> tmp;
set<vector<int>> s;
int N, M;
int number[10];
void dfs(int cnt) {
	if (cnt == M) {
		s.insert(tmp);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (number[arr[i]] > 0) {
			tmp.push_back(arr[i]);
			number[arr[i]]--;
			dfs(cnt + 1);
			number[arr[i]]++;
			tmp.pop_back();
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		number[num]++;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());

	dfs(0);
	
	for (set<vector<int>>::iterator it = s.begin(); it != s.end(); ++it) {
		vector<int> a = *it;
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << ' ';
		}cout << '\n';
	}


	return 0;
}