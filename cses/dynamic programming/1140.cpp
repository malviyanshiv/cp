#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

struct project{
	int a, b, p;

	project() : project(0, 0, 0) {}
	project(int a, int b, int p): a(a), b(b), p(p) {}
};

bool comp(project a, project b){
	if( a.a == b.a )
		return a.b < b.b;
	return a.a < b.a;
}

int32_t main(){
	IOS;
	int n, idx = 1;
	cin >> n;
	project inp[n];
	int days[2*n];
	for(int i = 0; i < n; i++){
		cin >> inp[i].a >> inp[i].b >> inp[i].p;
		days[2*i] = inp[i].a;
		days[2*i+1] = inp[i].b;
	}

	sort(days, days+2*n);
	map<int, int> mp;
	mp[days[0]] = idx++;
	for(int i = 1; i < 2*n; i++)
		if( days[i] != days[i-1] )
			mp[days[i]] = idx++;

	for(int i = 0; i < n; i++)
		inp[i].a = mp[inp[i].a], inp[i].b = mp[inp[i].b];

	sort(inp, inp+n, comp);

	int ans[idx] = {0}, pos = 1;
	ans[0] = 0;
	for(int i = 0; i < n; i++){
		while( pos < inp[i].a )
			ans[pos] = max(ans[pos], ans[pos-1]), pos++;
		ans[inp[i].b] = max(ans[inp[i].b], ans[inp[i].a-1] + inp[i].p);
	}

	while( pos < idx )
		ans[pos] = max(ans[pos], ans[pos-1]), pos++;

	cout << ans[idx-1] << endl;

	return 0;
}