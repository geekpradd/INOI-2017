#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define int long long
using namespace std;
 
int n, stren;
int *s;
int *e;
int **dp;
int ssu(int num){
	int dig = log10(num);
	int s = 0;
	for (int i=dig; i>=0; --i){
		int cur = num/pow(10, i);
		s += (cur%10);
	}
	return s*s*s;
}
 
int ans(int i, int sx){
	// sx represents value of strength
	// i is index
	if (dp[i][sx]!=-1){
		return dp[i][sx];
	}
	if (i!=n-1){
		dp[i][sx] = max(s[sx]*e[i] + ans(i+1, sx), ans(i+1, sx+1));
	}
	else {
		dp[i][sx] = s[sx]*e[i];
	}
	return dp[i][sx];
}
 
signed main(){
	// cin.tie(NULL);
	// ios_base::sync_with_stdio(false);
	
	cin >> n >> stren;
	s = new int[n];
	e = new int[n];
	s[0] = stren;
 
	for (int i=1; i<n; ++i){
		s[i] = s[i-1] + ssu(s[i-1]);
	}
 
	for (int i=0; i<n; ++i){
		cin >> e[i];
	}
	dp = new int*[n];
	for (int i=0; i<n; ++i){
		dp[i] = new int[n];
		for (int j=0; j<n; ++j){
			dp[i][j] = -1;
		}
	}
	cout << ans(0, 0) << endl;
	return 0;
 
} 