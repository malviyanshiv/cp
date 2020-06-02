#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define MAX 100001

int32_t main(){
	IOS;
	int n;
	cin >> n;
	int val[n];
	for(int i = 0; i < n; i++)
		cin >> val[i];

	vector<bool> amount(MAX, false);
	amount[0] = true;
	for(int i = 0; i < n; i++){
		for(int j = MAX-1; j >= val[i]; j--)
			if( amount[j-val[i]] )
				amount[j] = true;
	}

	int cnt = 0;
	for(int i = 1; i < MAX; i++)
		if( amount[i] )
			cnt++;

	cout << cnt << endl;
	for(int i = 1; i < MAX; i++)
		if( amount[i] )
			cout << i << " ";
	cout << endl;

	return 0;
}