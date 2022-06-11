#include"bits/stdc++.h"
#include<random>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

string MakeSAT(int n) {
	random_device seed_gen;
	mt19937 engine(seed_gen());
	string ans;
	if (n == 1) {
		if (engine() % 3) {
			ans += "￢";
		}
		ans += "X";
		return ans;
	}
	if (n == 2) {
		if (engine() % 3) {
			ans += "￢";
		}
		ans += "X";
		if (engine() % 2) {
			ans += "∨";
		}
		else {
			ans += "∧";
		}
		if (engine() % 3) {
			ans += "￢";
		}
		ans += "X";
		return ans;
	}
	int rand = (engine() % (1 << (n - 1)) + 1) % (1 << (n - 1));
	string andor;
	if (engine() % 5)andor = "∧";
	else andor = "∨";
	int cnt = 1;
	rep(i, n - 1) {
		if (rand & (1 << i)) {
			if (cnt == 1) {
				ans += MakeSAT(cnt);
			}
			else {
				if (engine() % 2) {
					ans += "￢";
				}
				ans += "(" + MakeSAT(cnt) + ")";
			}
			ans += andor;
			cnt = 1;
		}
		else cnt++;
	}
	if (cnt == 1 || cnt == n) {
		ans += MakeSAT(cnt);
	}
	else {
		ans += "(" + MakeSAT(cnt) + ")";
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	rep(i, 10) cout << MakeSAT(n) << endl;
	return 0;
}
