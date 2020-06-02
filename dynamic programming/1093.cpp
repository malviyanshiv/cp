#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define MOD 1000000007

int fpow(int bs, int pw){
	int res = 1;
	while( pw ){
		if( pw&1 )
			res = (res*bs)%MOD;
		bs = (bs*bs)%MOD;
		pw = pw>>1;
	}

	return res;
}

int32_t main(){
	IOS;
	int n;
	cin >> n;
	int tot = n*(n+1);
	if( tot%4 ){
		cout << 0 << endl;
	}else{
		tot = tot/4;
		vector<int> ways(tot+1, 0);
		ways[0] = 1;
		for(int i = 1; i <= n; i++){
			for(int j = tot; j >= i; j--)
				if( ways[j-i] )
					ways[j] = (ways[j] + ways[j-i])%MOD;
		}

		cout << (ways[tot]*fpow(2, MOD-2))%MOD << endl;
	}

	return 0;
}