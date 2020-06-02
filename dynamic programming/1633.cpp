#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define MOD 1000000007

int32_t main(){
	IOS;
	int n;
	cin >> n;
	int dp[n+1];
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		dp[i] = 0;
		for(int j = 1; j <= 6; j++)
			if( i-j >= 0 )
				dp[i] = (dp[i] + dp[i-j])%MOD;
	}

	cout << dp[n] << endl;
	return 0;
}