//Link da questao: https://dmoj.ca/problem/acsl1p4

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define joaobobao ios_base::sync_with_stdio(false); cin.tie(NULL)

int n, k;
vector<vector<int>> g;
vector<int> visited, parent;
set<int> ans;

void dfs(int v){

    visited[v] = 1;

    for(auto u : g[v]){

        if(visited[u] == 1){

            int curr = v;
            ans.insert({u});

            while(curr != u and curr != -1){

                ans.insert({curr});
                curr = parent[curr];
            }
        }

        if(!visited[u]){

            parent[u] = v;
            dfs(u);
        }
    }

    visited[v] = 2;
}

void solve() {

    cin >> n >> k;
    g.resize(n+1);
    visited.resize(n+1, 0);
    parent.resize(n+1, -1);
    
    for(int i=1;i<=k;i++){

        int a, b; cin >> a >> b;
        int pa, pb; cin >> pa >> pb;

        pa > pb? g[a].pb(b) : g[b].pb(a);
    }

    for(int i=1;i<=n;i++){

        if(!visited[i]) dfs(i);
    }

    cout << ans.size() << endl;
}


signed main() {

    joaobobao;

    int t = 1;
    //cin >> t;

    while (t--) solve();

    return 0;
}
