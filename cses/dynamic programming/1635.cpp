#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define MOD 1000000007

int32_t main(){
	IOS;
	int n, x;
	cin >> n >> x;
	vector<int> coins(n);
	for(int i = 0; i < n; i++)
		cin >> coins[i];

	vector<int> ways(x+1, 0);
	ways[0] = 1;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < n; j++)
			if( i+coins[j] <= x )
				ways[i+coins[j]] = (ways[i+coins[j]] + ways[i])%MOD;
	}

	cout << ways[x] << endl;
	return 0;
}