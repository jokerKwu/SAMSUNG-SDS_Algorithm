#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<unordered_set>
#include<stdlib.h>
using namespace std;
unordered_set<int> arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	int testCase = 1;
	int lineCnt = 0;
	while (true) {
		cin >> a >> b;
		if (a < 0 && b < 0) break;
		while (true) {
			if (a == 0 && b == 0)
				break;
			arr.insert(a);
			arr.insert(b);
			cin >> a >> b;
			lineCnt++;
		}	
		if (lineCnt + 1 == arr.size()||lineCnt == 0) cout << "Case " << testCase++ << " is a tree.\n";
		else {
			cout << "Case " << testCase++ << " is not a tree.\n";
		}
		string trash;
		getline(cin, trash);
		arr.clear();
		lineCnt = 0;
	}


	return 0;
}