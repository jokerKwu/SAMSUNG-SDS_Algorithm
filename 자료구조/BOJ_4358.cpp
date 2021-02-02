#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 1000002
int N;
int tree[MAX * 4];
//������ (�ش� ������ ������ϱ�)

int query(int start, int end, int node, int rank) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	//���� �ڽ�
	if (rank <= tree[node*2]) {
		return query(start, mid, node * 2, rank);
	}
	//������ �ڽ�
	else {
		return query(mid + 1, end, node * 2 + 1, rank - tree[node * 2]);
	}

}

//������Ʈ
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
		//2�� �����ε� ������ ��������ŭ ����.
		if (a == 2) {
			cin >> c;
			update(1, MAX, 1, b, c);
		}
		//���� ���
		else {
			int favor = query(1, MAX, 1, b);
			cout << favor << '\n';
			update(1, MAX, 1, favor, -1);
		}
	}
	

	return 0;
}
