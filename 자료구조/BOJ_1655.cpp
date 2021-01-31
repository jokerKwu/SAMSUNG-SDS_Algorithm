#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> v;
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int>> min_pq;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		//최대 힙의 크기는 최소 힙의 크기보다 같거나 +1
		if (max_pq.size() == min_pq.size()) {
			max_pq.push(num);
		}
		else {
			min_pq.push(num);
		}
		if (min_pq.size() == 0||max_pq.top() <= min_pq.top()) {
			cout << max_pq.top() << '\n';
		}
		else {
			while (max_pq.top() > min_pq.top()) {
				int max_num = max_pq.top();
				int min_num = min_pq.top();
				max_pq.pop();
				min_pq.pop();
				max_pq.push(min_num);
				min_pq.push(max_num);
			}
			cout << max_pq.top() << '\n';
		}
		
	}
	
	
	return 0;

}