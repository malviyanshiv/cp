#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int n, x;
	cin >> n >> x;
	int books[n][2];
	for(int i = 0; i < n; i++)
		cin >> books[i][0];
	for(int i = 0; i < n; i++)
		cin >> books[i][1];

	vector<int> dp(x+1, -1);
	dp[0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = x; j >= books[i][0]; j--)
			if( dp[j-books[i][0]] != -1 )
				dp[j] = max(dp[j], dp[j-books[i][0]]+books[i][1]);
	}

	int ans = 0;
	for(int i = 1; i <= x; i++)
		ans = max(ans, dp[i]);

	cout << ans << endl;
	
	return 0;
}