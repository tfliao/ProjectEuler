#include <iostream>
#include <vector>
using namespace std;

// limitation of year is interesting, it show that we can solve it by just counting it...
// 1. calculate the day of starting date
// 2. check each month

#define DATE(x) ((((x)%7) + 7) % 7)

long y1, y2, m1, m2, d1, d2;

// 1-based array
int dm[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // days in month

bool isleap(long y)
{
	if (y%400 == 0) return true;
	if (y%100 == 0) return false;
	if (y%4 == 0) return true;
	return false;
}

int solv()
{
	int start = 1; // 1900/1/1 is Monday, let 0 be Sunday, wanna to make it 0000/1/1
	int cnt = 0;
	
	// make start point to first day of month
	if (d1 != 1) {
		d1 = 1;
		m1 ++;
		if (m1 > 12) m1 = 1, ++y1;
	}
	
	// 1. move start to start-date
	--y1; // run over y1-1 years, but not y1 years
	start += DATE((DATE(y1)*365) + y1/4 - y1/100 + y1/400);
	++y1;
	for (int i=1;i<m1;++i) {
		start += dm[i];
		if (i == 2 && isleap(y1)) ++start;
	}
	
	start = DATE(start + d1-1);

//	printf("=> %d\n", start);

	// 2. go over every year
	int m = m1;
	int dt = start;
	for (long y=y1;y<=y2;++y) {
		int mbnd = (y==y2?m2:12); // month bound
		for (m;m<=mbnd;++m){
			if (dt == 0) {
				++cnt;
//				printf("%ld/%d/%d\n", y, m, 1);
			}
			dt = DATE(dt + dm[m] + (m==2 && isleap(y)?1:0));
		}
		m = 1;
	}
	
	return cnt;
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> y1 >> m1 >> d1;
		cin >> y2 >> m2 >> d2;
		
		if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1==y2 && m1 == m2 && d1 > d2)) {
			long t;
			t = y1; y1 = y2; y2 = t;
			t = m1; m1 = m2; m2 = t;
			t = d1; d1 = d2; d2 = t;
		}
		cout << solv() << endl;
	}
	
	return 0;
}