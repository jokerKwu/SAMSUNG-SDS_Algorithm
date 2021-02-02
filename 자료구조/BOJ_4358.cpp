#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000002
int N;
int tree[MAX * 4];
//쿼리문 (해당 순위에 값출력하기)

int query(int start, int end, int node, int rank) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	//왼쪽 자식
	if (rank <= tree[node*2]) {
		return query(start, mid, node * 2, rank);
	}
	//오른쪽 자식
	else {
		return query(mid + 1, end, node * 2 + 1, rank - tree[node * 2]);
	}

}

//업데이트
void update(int start, int end, int node, int index, int diff) {
	if (index < start || end < index) return;
	tree[node] += diff;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid + 1, end, node * 2 + 1, index, diff);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0;i < N;i++) {
		int a, b, c;
		cin >> a >> b;
		//2가 삽입인데 음수면 음수개만큼 뺀다.
		if (a == 2) {
			cin >> c;
			update(1, MAX, 1, b, c);
		}
		//순위 출력
		else {
			int favor = query(1, MAX, 1, b);
			cout << favor << '\n';
			update(1, MAX, 1, favor, -1);
		}
	}
	

	return 0;
}
