#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long gcd(long x, long y)
{
	while (x%y != 0){
		long t = x%y;
		x = y;
		y = t;
	}
	return y;
}

long solv(long N)
{
	// LCD them
	long lcd = 1;
	for (long i=2;i<=N;++i) {
		lcd = lcd / gcd(lcd, i) * i;
	}
	return lcd;
	
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