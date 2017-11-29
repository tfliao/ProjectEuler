#include <iostream>
using namespace std;

#define trillion (1000000000000LL)
#define billion  (1000000000LL)
#define million  (1000000LL)
#define thousand (1000LL)
#define hundred  (100LL)

string words[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"X", "X", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

void append_ws(string& s, const string& t)
{
	if (s.empty()) s = t;
	else if (t.empty()) ;
	else s += " " + t;
}

string toWord(long X)
{
	string r;
	if (X >= trillion) {
		append_ws(r, toWord(X/trillion));
		append_ws(r, "Trillion");
		X %= trillion;
	}
	if (X >= billion) {
		append_ws(r, toWord(X/billion));
		append_ws(r, "Billion");
		X %= billion;
	}
	if (X >= million) {
		append_ws(r, toWord(X/million));
		append_ws(r, "Million");
		X %= million;
	}
	if (X >= thousand) {
		append_ws(r, toWord(X/thousand));
		append_ws(r, "Thousand");
		X %= thousand;
	}
	if (X >= hundred) {
		append_ws(r, toWord(X/hundred));
		append_ws(r, "Hundred");
		X %= hundred;
	}
	if (X < 20) {
		append_ws(r, words[X]);
	} else {
		append_ws(r, tens[X/10]);
		if (X%10 > 0)
			append_ws(r, words[X%10]);
	}
	return r;
}

int main()
{
	int T;
	long N;
	cin >> T;
	while (T--) {
		cin >> N;
		if (N == 0) cout << "Zero" << endl;
		else cout << toWord(N) << endl;
	}
	
	return 0;
}
