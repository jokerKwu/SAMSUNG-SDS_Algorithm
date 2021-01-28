#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//유큻리드 호제법
int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	//분자
	int tmpA = a * d;
	int tmpB = b * c;
	int tmpC = tmpA + tmpB;
	//분모
	int tmpD = b * d;
	int res = gcd(tmpC, tmpD);
	cout << tmpC / res << ' ' << tmpD / res << '\n';
	

	return 0;
}
