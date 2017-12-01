#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// some observation:
// b is prime, so that n=0 make a prime
// n < b, if n == b then n(n+a)+b is not prime

#define MXN (2000)

vector<int> counter;
vector< pair<int,int> > ans;

// create a prime table, max prime is a=b=n=N => N^2 + N*N + N => 2*N^2 + N
#define MXP (2 * MXN*MXN + MXN)
bool np[MXP] = {true, true};

void buildprime()
{
	for (int i=2;i*i <= MXP;++i) {
		if (!np[i]) {
			for (int j=i+i;j <= MXP; j+=i) np[j] = true;
		}
	}
}

int counting(int a, int b)
{
	int cnt = 0;
	for (int n=0;n<b;++n) {
		int p = n*n + a*n + b;
		if (p <=0 || np[p]) return cnt;
		++cnt;
	}
	return cnt;
}

void buildanswer(int bound)
{
	// bacuse n < b, we can try b to best answer now
	int best = counter[bound-1];
	int besta = ans[bound-1].first, bestb = ans[bound-1].second;
	for (int b = bound; b > best; --b) {
		if (np[b]) continue;
//		printf("bound %d, b=%d\n", bound, b);
		for (int a=-sqrt(b*10);a < 0;++a) {
			// need a cut here, but no idea now
			int r = counting(a, b);
			if (r > best) {
				best = r;
				besta = a;
				bestb = b;
			}
		}
	}
	counter[bound] = best;
	ans[bound] = make_pair(besta, bestb);
}


void build()
{
	buildprime();
	ans.resize(MXN+1);
	counter.resize(MXN+1);
	ans[42] = make_pair(-1, 41);
	counter[42] = 42;
	
	for (int i=43;i<=MXN;++i) {
		buildanswer(i);
	}
}


int main()
{
	build();

//	for (int i=42;i<=MXN;++i)
//		cout << ans[i].first << ' ' << ans[i].second << endl;

	long N;
	cin >> N;
	cout << ans[N].first << ' ' << ans[N].second << endl;
	
	return 0;
}