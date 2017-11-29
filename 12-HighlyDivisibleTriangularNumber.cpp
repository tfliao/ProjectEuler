#include <iostream>
#include <vector>
using namespace std;

#define MX (1000)

// just try to find divides

vector<int> ans;

int divisor(int x)
{
	int r = 1;
	for (int p = 2; p*p <= x; ++p) {
		if (x%p == 0) {
			int cnt = 0;
			while (x%p == 0) ++cnt, x/=p;
			r *= (cnt+1);
		}
	}
	if (x > 1) {
		r *= 2;
	}
	return r;
}

void build()
{
	int sum = 0;
	for(int i=1;ans.size() < MX;++i) {
		sum += i;
		int d = divisor(sum);
		while (ans.size() < d) ans.push_back(sum);
	}
}

int main()
{
	build();
	int T, N;
	cin >> T;
	while(T--) {
		cin >> N;
		cout << ans[N] << endl;
	}
	
	return 0;
}