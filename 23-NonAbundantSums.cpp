#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define BOUND (28123)
// according to the problem description, larger than the bound is YES

vector<int> abundant;

bool isAbundant(int x)
{
	int sum = 1;
	for (int p=2;p*p<=x;++p) {
		if (x%p == 0) {
			if (x/p == p) sum += p;
			else sum += p + x/p;
		}
	}
//	cout << x << ": " << sum << " (" << (sum > x?"Y":"N") << endl;
	return sum > x;
}

string solv(int N);

void build()
{
	for (int i=12;i<=BOUND;++i) {
		if (isAbundant(i)) {
			abundant.push_back(i);
		}
	}
}

string solv(int N)
{
	if (N > BOUND) return "YES";

	for(int i=0;i < abundant.size() && abundant[i] < N; ++i) {
		int r = N - abundant[i];
		int p = *lower_bound(abundant.begin(), abundant.end(), r);
		if (p == r) {
			return "YES";
		}
	}
	return "NO";
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