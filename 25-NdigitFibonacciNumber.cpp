#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MXN (5000)

int ans[MXN+1] = {0, 1};

void build()
{
	long double f1 = 1, f2 = 1, ff;
	long double base = 10;
	int t = 2;
	
	for (int i=0;i<1000;++i) {
		f1 /= 10;
		f2 /= 10;
		base /= 10;
	}
	
	
	for (int d=2;d<=MXN;++d) {
		do {
			ff = f1 + f2;
			f1 = f2;
			f2 = ff;
			++t;
		} while (ff < base);
		ans[d] = t;
		base *= 10;
//		printf("%d: %d %lle\n", d, ans[d], ff);
	}
}

int solv(long N) {
	return ans[N];
}

int main()
{
	build();

	int T;
	long N;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << solv(N) << endl;
	}
	
	return 0;
}