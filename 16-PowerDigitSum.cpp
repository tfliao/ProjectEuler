#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MXN (10000)

int ans[MXN+1] = {1};

int digit_sum(const vector<int>& X)
{
	int sum = 0;
	for (int i=0;i<X.size();++i) {
		int x = X[i];
		while (x > 0) { sum += x%10; x/=10; }
	}
	return sum;
}

void build()
{
	const int R = 1000000000;
	vector<int> p({1});
	for (int i=1;i<=MXN;++i) {
		int c = 0;
		for (int j=0;j<p.size();++j) {
			p[j] = p[j] * 2 + c;
			c = p[j]/R;
			p[j] -= c*R;
		}
		if (c) p.push_back(c);
		
		ans[i] = digit_sum(p);
	}
}


int main() {
	build();
	
	
    int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << ans[N] << endl;
	}
    return 0;
}
