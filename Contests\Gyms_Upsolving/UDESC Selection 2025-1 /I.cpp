#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define joaobobao cin.tie(0)->sync_with_stdio(0)

int dfs(int v, vector<vector<int>> &g, vector<int> &visited, vector<char> &storage){

    visited[v] = 1;

    for(auto x : g[v]){ 

        if(!visited[x]){
            if(dfs(x,g,visited,storage)) return 1;
        }

        else if(visited[x] == 1) return 1;
    }

    storage.pb(v + 'a');
    visited[v] = 2;

    return 0;
}

void topografia(vector<vector<int>> &g, vector<char> &storage, vector<int> &visited, vector<string> &s){

    for(int i=0;i<26;i++){

        if(!visited[i]){

            if(dfs(i, g, visited, storage)){

                cout << "NAO\n";
                return;
            }
        }
    }

    cout << "SIM\n";

    for(int i=0;i<storage.size();i++){

        cout << storage[i];
    }
    cout << endl;
}

void solve(){

    int n; cin >> n;
    vector<vector<int>> g(26);
    vector<string>s(n);
    vector<int>visited(26, 0);
    vector<char>storage;

    for(int i=0;i<n;i++) cin >> s[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<s[i].size()-1;j++){

            if(s[i][j] != s[i][j+1]){
                
                g[s[i][j+1] - 'a'].pb(s[i][j] - 'a');
            }
        }
    }

    topografia(g, storage, visited, s);
    
}

signed main(){

    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
