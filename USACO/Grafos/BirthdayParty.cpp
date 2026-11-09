//Link da questão: https://open.kattis.com/submissions/20851232

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define speedio cin.tie(0) -> sync_with_stdio(0)

int p = 1, c = 1;

bool valido(int u, int v, int a, int b){

    if(u == a or u == b){
        if(v == a or v == b) return false;
    }

    return true;
}

void dfs(int v, int a, int b, vector<bool> &visited, vector<vector<int>> &g){

    visited[v] = 1;
    //cout << v << " ";

    for(auto u : g[v]){

        if(!visited[u] and valido(u, v, a, b)){

            dfs(u, a, b, visited, g);
        }
    }
}

void solve(){

    cin >> p >> c;
    if(p == 0 and c == 0) return;

    vector<vector<int>> g(p);
    vector<pair<int,int>> conec(c);

    for(int i=0;i<c;i++){

        int a, b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        conec[i] = {a, b};
    }

    for(int i=0;i<c;i++){

        vector<bool>visited(p, false);

        auto [a, b] = conec[i];
        //cout << "[" << a << ", " << b << "]\n";

        dfs(0, a, b, visited, g);
        //cout << "------\n";
        
        for(int j=0;j<p;j++){

            if(!visited[j]){
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

signed main(){

    speedio;

    int t=1; //cin >> t;

    while(p != 0 or c != 0) solve();

    return 0;
}  
