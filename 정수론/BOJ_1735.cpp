#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//�������� ȣ����
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
	
	//����
	int tmpA = a * d;
	int tmpB = b * c;
	int tmpC = tmpA + tmpB;
	//�и�
	int tmpD = b * d;
	int res = gcd(tmpC, tmpD);
	cout << tmpC / res << ' ' << tmpD / res << '\n';
	

	return 0;
}
