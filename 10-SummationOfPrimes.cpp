#include <iostream>
#include <vector>

using namespace std;

#define MXP 1000000

bool notp[MXP+1];
vector<int> prime({2});

void build()
{
	for (int i=3;i<=MXP;i+=2) {
		if (!notp[i]) {
			prime.push_back(i);
			for(int k=i;k<=MXP;k+=i) notp[k] = true;
		}
	}
}

long solv(int N)
{
	long sum = 0;
	for (int x : prime) {
		if (x > N) return sum;
		sum += x;
	}
	return sum;
}

int main(){
	build();

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
		cout << solv(n) << endl;
    }
    return 0;
}
