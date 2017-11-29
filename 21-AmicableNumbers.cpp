#include <iostream>
#include <vector>
using namespace std;

// I think only few pair
#define MXN (100000)

int ans[MXN+1] = {0, 0};

long SPD[MXN+1] = {0, 0}; // sum of proper dividors
// amicable number no need to be pair
long calc_spd(long x)
{
	// just try using lszy method
	long sum = 1;
	for (long i=2;i*i <= x;++i) {
		if (x%i == 0) {
			if (x/i==i) sum += i;
			else sum += i + x/i;
		}
	}
	return sum;
}

void build()
{
	for (int i=2;i<=MXN;++i) {
		SPD[i] = calc_spd(i);
	}
	for (int i=2;i<=MXN;++i) {
		long partner = SPD[i];
		ans[i] = ans[i-1];
		if (i != partner && partner <= MXN && SPD[partner] == i){
//			printf("%d (%d)\n", i, partner);
			ans[i] += i;
		}
	}
}


int main()
{
	build();

	int T;
	long N;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << ans[N] << endl;
	}
	
	return 0;
}