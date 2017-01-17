#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#define int long long
using namespace std;

int ssu(int num){
	int dig = log10(num);
	int s = 0;
	for (int i=dig; i>=0; --i){
		int cur = num/pow(10, i);
		s += (cur%10);
	}
	return s*s*s;
}


signed main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, stren;
	int *s;
	int *e;
	s = new int[n];
	e = new int[n];

	cin >> n >> stren;
	s[0] = stren;

	for (int i=1; i<n; ++i){
		s[i] = s[i-1] + ssu(s[i-1]);
	}

	for (int i=0; i<n; ++i){
		cin >> e[i];
	}
	int dp[n][n];
	for (int x = n-1; x>=0; --x){
		dp[n-1][x] = s[x]*e[n-1];
	}
	for (int i = n-2; i>=0; --i){
		dp[i][n-1] = s[n-1]*e[i] + dp[i+1][n-1];
		for (int x=n-2; x>=0; --x){
			dp[i][x] = max(s[x]*e[i] + dp[i+1][x], dp[i+1][x+1]);

		}
	}
	cout << dp[0][0] << endl;
	return 0;

}