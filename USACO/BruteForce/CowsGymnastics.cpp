//Link para a questao: https://usaco.org/index.php?page=viewproblem2&cpid=963

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

void solve(){

    int k, n; cin >> k >> n;

    vector<vector<int>> grid(k+1, vector<int>(n+1));

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){

            cin >> grid[i][j];
        }
    }

    vector<vector<int>> maiorque(n+1);

    for(int i=1;i<=k;i++){
        for(int j=1;j<n;j++){
            for(int l=j+1;l<=n;l++){
 
                maiorque[grid[i][j]].push_back(grid[i][l]);
            }
        }
    }

    for(int i=1;i<=n;i++){

        sort(all(maiorque[i]));

        auto last = unique(maiorque[i].begin(), maiorque[i].end());

        maiorque[i].erase(last, maiorque[i].end());
    }

    int ans = 0;

    for(int i=1;i<=n;i++){
        for(auto b : maiorque[i]){

            bool da = true;

            for(auto c : maiorque[b]){

                if(c == i) da = false;
            }

            if(da) ans++;
        }
    }

    cout << ans << endl;
}

signed main(){

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}