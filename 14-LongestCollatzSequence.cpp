#include <iostream>
#include <cstring>
using namespace std;

#define MXN (5000000)

int cycle[MXN+1] = {0, 1};
int ans[MXN+1] = {0, 1};

void build()
{
	memset(cycle, -1, sizeof(cycle));
	cycle[0] = 0;
	cycle[1] = 1;
	int best = 1;
	int idx = 1;
	for (int i=2;i<=MXN;++i) {
		long p = i;
		int cnt = 0;
		while (true) {
			if (p <= MXN && cycle[p] != -1) {
				cycle[i] = cnt + cycle[p];
				break;
			}
			p = (p&1?3*p+1:p/2);
			cnt ++;
		}
//		printf("%d: %d\n", i, cycle[i]);
		if (cycle[i] >= best) {
			best = cycle[i];
			idx = i;
		}
		ans[i] = idx;
	}
}

int main()
{
	build();
	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << ans[N] << endl;
	}
	return 0;
}