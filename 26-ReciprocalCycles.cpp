#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MXN (10000)

int ans[MXN+1] = {0, 0, 0, 3};
int r[MXN];

int cycle(int x)
{
	for (int i=0;i<x;++i) r[i] = -1;
	
	int rr = 1;
	int idx = 0;
	while (rr != 0) {
		rr = rr * 10 % x;
		++ idx;
		if (r[rr] != -1) {
			return idx - r[rr];
		}
		r[rr] = idx;
	}

	return 0;
}

void build()
{
	int longest = 1;
	for (int i=4;i<=MXN;++i) {
		int c = cycle(i);
		if (c > longest) { ans[i] = i; longest = c; }
		else ans[i] = ans[i-1];
		
//		cout << ans[i] << " " << longest << endl;
	}
}

int solv(long N) {
	return ans[N-1];
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