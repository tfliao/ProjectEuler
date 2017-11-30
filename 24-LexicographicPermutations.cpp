#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// think about 3! = 6
/*
abc = 0 => 0, 0, 0
acb = 1 => 0,
bac = 2
bca = 3
cab = 4 => 2*2!, 0, 0
cba = 5 => 2*2!, 1*1, 0
*/

string solv(long N)
{
	string r;
	string base = "abcdefghijklm";
	long div = 479001600;
	-- N;

	for (int i=12;i>0;--i) {
		long d = N / div;
		r += base[d];
		base.erase(base.begin()+d);
		N %= div; 
		div /= i;
	}
	r += base[0];
	
	return r ;
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