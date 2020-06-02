#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main(){
	IOS;
	int a, b;
	const int inf = 1000000;
	cin >> a >> b;
	if( a > b )
		swap(a, b);

	vector<vector<int>> dp(a+1, vector<int>(b+1, inf));
	for(int i = 1; i <= a; i++)
		for(int j = 1; j <= b; j++){
			if( i == j ){
				dp[i][j] = 0;
				continue;
			}
			for(int x = 1; x < i; x++)
				dp[i][j] = min(dp[i][j], dp[x][j] + dp[i-x][j] + 1);
			for(int x = 1; x < j; x++)
				dp[i][j] = min(dp[i][j], dp[i][x] + dp[i][j-x] + 1);
		}

	cout << dp[a][b] << endl;

	return 0;
}