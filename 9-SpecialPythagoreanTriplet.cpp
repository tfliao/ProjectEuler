#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MXN (3000)

long ans[MXN+1];

void build()
{
	memset(ans, -1, sizeof(ans));
	for (int c=1;c<MXN;++c) {
		for (int b=1;b<c;++b) {
			int a2 = c*c - b*b;
			int a = sqrt(a2);
			if (a*a == a2) {
				int s = a+b+c;
				int p = a*b*c;
//				printf("%d %d %d\n", a, b, c);
				if (s <= MXN && p > ans[s]) ans[s] = p;
			}
		}
	}
}

int main(){
	build();
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
		cout << ans[n] << endl;
    }
    return 0;
}
