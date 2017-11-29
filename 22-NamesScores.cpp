#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// sort index, but not string? 
// should be timeout
// .... passed

vector<string> names;

void process()
{
	// let try sort the string directly
	sort(names.begin(), names.end());
}

int lookup(const string& q)
{
	int idx = lower_bound(names.begin(), names.end(), q) - names.begin() + 1;
	int sum = 0;
	for (int i=0;i<q.length();++i) sum += q[i] - 'A' + 1;
	return sum * idx;
}

void str_toupper(string& s)
{
	for (int i=0;i<s.length();++i) {
		s[i] = toupper(s[i]);
	}
}

int main()
{
	long N, Q;

	cin >> N;
	names.resize(N);
	for(int i=0;i<N;++i) {
		cin >> names[i];
		str_toupper(names[i]);
	}
	process();
	cin >> Q;
	for(int i=0;i<Q;++i) {
		string query;
		cin >> query;
		str_toupper(query);
		cout << lookup(query) << endl;
	}
	
	return 0;
}