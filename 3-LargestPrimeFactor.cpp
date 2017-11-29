#include <iostream>
using namespace std;

long solv(long N)
{
	long lastP = -1;
	for (long p = 2; p*p <= N; ++p) {
		while (N%p == 0) {
			lastP = p;
			N /= p;
		}
	}
	if (N>1) {
		lastP = N;
	}
	return lastP;
}


int main()
{
	int T;
	long N;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << solv(N) << endl;
	}
	
	return 0;
}