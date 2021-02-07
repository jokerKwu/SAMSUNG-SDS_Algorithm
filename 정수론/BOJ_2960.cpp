#include<iostream>
#include<vector>
using namespace std;
vector<int> prime;
bool notPrime[1002];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, K;
	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		if (!notPrime[i]) {
			prime.push_back(i);
			for (int j = i + i; j <= N; j += i) {
				if (!notPrime[j]) {
					prime.push_back(j);
					notPrime[j] = true;
				}
			}
		}
	}
	cout << prime[K-1] << '\n';

	return 0;
}