#include <bits/stdc++.h>
#include <utility>
#define iii pair< pair<int, int>, int>
#define ii pair<int, int>
#define REP(j) for (int i=0; i<j; ++i)
using namespace std;

int dfs(int src, vector<bool> &visited, vector<int> adj[], int n){
	visited[src] = true;
	int vis = 4 - adj[src].size();
	for (int i=0; i<adj[src].size(); ++i){
		int to = adj[src][i];
		// cout << "going to " << to << endl;
		if (!visited[to]){
			int incr = dfs(to, visited, adj, n);
			vis += incr;
		}
	}
	return vis;
}

signed main(){
	int r, c, n;
	cin >> r >> c >> n;

	vector<iii> cult(n);
	vector<iii> culv(n);
	for (int i=0; i<n; ++i){
		int a, b;
		cin >> a >> b;
		cult[i] = iii(ii(a, b), i);
		culv[i] = iii(ii(b, a), i);
	}
	sort(cult.begin(), cult.end());
	sort(culv.begin(), culv.end());

	vector<int> adj[n];
	for (int i=0; i<n-1; ++i){
		iii cur = cult[i];
		int id = cur.second;
		int x = cur.first.first;
		int y = cur.first.second;

		iii next = cult[i+1];
		int id_ = next.second;
		int x_ = next.first.first;
		int y_ = next.first.second;
		if (x == x_){
			if (y_ - y ==1){
				adj[id].push_back(id_);
				adj[id_].push_back(id);

			}
		}
	}
	for (int i=0; i<n-1; ++i){
		iii cur = culv[i];
		int id = cur.second;
		int x = cur.first.second;
		int y = cur.first.first;

		iii next = culv[i+1];
		int id_ = next.second;
		int x_ = next.first.second;
		int y_ = next.first.first;
		if (y == y_){
			if (x_ - x ==1){
				adj[id].push_back(id_);
				adj[id_].push_back(id);

			}
		}
	}
	// cout << "GRAPH" << endl;
	// for (int i=0; i<n; ++i){
	// 	cout << "I " << i << endl;
	// 	for (int j=0; j<adj[i].size(); ++j){
	// 		cout << adj[i][j] << endl;
	// 	}
	// }
	vector<bool> visited(n, false);
	int total = 0;

	for (int i=0; i<n; ++i){
		// cout << "i " << i << endl;
		// cout << "visited status " << visited[i] << endl;
		if (!visited[i]){
			int ans = dfs(i, visited, adj, n);
			// cout << "got " << ans << endl;
			total = max(total, ans);
		}
	}

	cout << total << endl;

	return 0;
}