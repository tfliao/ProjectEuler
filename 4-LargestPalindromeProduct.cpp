#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> palindrome;

bool check(int x)
{
	int d[6];
	for (int i=0;i<6;++i) { d[i] = x%10; x/=10; }
	return d[0] == d[5] && d[1] == d[4] && d[2] == d[3];
}

void build()
{
	for(int i=100;i<1000;++i) {
		for (int j=i;j < 1000 && i*j < 1000000;++j) {
			if (check(i*j)) {
				palindrome.push_back(i*j);
			}
		}
	}
	sort(palindrome.begin(), palindrome.end());
}


int main()
{
	build();
	
	int T;
	long N;
	cin >> T;
	while (T--) {
		cin >> N;
		cout << *(--lower_bound(palindrome.begin(), palindrome.end(), N)) << endl;
	}
	
	return 0;
}