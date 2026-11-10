//Link da questao: https://cses.fi/problemset/task/1682

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

void dfs(int v, vector<int> &visited, vector<vector<int>> &g){

    visited[v] = 1;

    for(auto u : g[v]){

        if(!visited[u]){

            dfs(u, visited, g);
        }
    }
}

void solve() {

    int n, m; cin >> n >> m;
    vector<vector<int>> g(n+1), gt(n+1);
    vector<int> visited(n+1, false);

    for(int i=0;i<m;i++){

        int a, b; cin >> a >> b;
        g[a].pb(b);
        gt[b].pb(a);
    }

    dfs(1, visited, g);
    for(int i=1;i<=n;i++){

        if(!visited[i]){

            cout << "NO\n";
            cout << '1' << " " << i << endl;
            return;
        }
    }

    fill(all(visited), 0);
    dfs(1, visited, gt);

    for(int i=1;i<=n;i++){

        if(!visited[i]){

            cout << "NO\n";
            cout << i << " " << 1 << endl;
            return;
        }
    }

    cout << "YES\n";
}


signed main() {

    fastio;

    int t = 1;
    //cin >> t;

    while (t--) solve();

    return 0;
}   
