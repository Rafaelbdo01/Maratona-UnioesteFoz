//Link da questão: https://usaco.org/index.php?page=viewproblem2&cpid=944

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)

int n, m, ans = 1e9;
vector<bool> visited;
vector<vector<int>> g;
vector<pair<int,int>> loc;
int maix, maiy, menx, meny;

void dfs(int v){

    visited[v] = 1;

    for(auto u : g[v]){

        if(!visited[u]){

            menx = min(menx, loc[u].first);
            meny = min(meny, loc[u].second);
            maix = max(maix, loc[u].first);
            maiy = max(maiy, loc[u].second);

            dfs(u);
        }
    }
}

void solve(){

    cin >> n >> m;
    g.resize(n+1);
    loc.resize(n+1);
    visited.resize(n+1, false);

    for(int i=1;i<=n;i++) cin >> loc[i].first >> loc[i].second;

    for(int i=1;i<=m;i++){

        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    for(int i=1;i<=n;i++){

        if(!visited[i]){
            
            menx = maix = loc[i].first;
            meny = maiy = loc[i].second;
            dfs(i);

            ans = min(ans, 2 * ((maix - menx) + (maiy - meny)));
        }
    }   

    cout << ans << endl;
}

signed main(){

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    joaobobao;

    int t=1; // cin >> t;

    while(t--) solve();

    return 0;
}
