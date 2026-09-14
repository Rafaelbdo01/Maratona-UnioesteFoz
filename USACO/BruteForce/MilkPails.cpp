//Link da questao: https://usaco.org/index.php?page=viewproblem2&cpid=615

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

void solve(){

    int x,y,m;
    cin >> x >> y >> m;

    int ans = 0;

    int xbound = m/x, ybound = m/y;

    for(int i=0;i<=xbound;i++){
        for(int j=0;j<=ybound;j++){

            int atual = (x * i) + (y * j);

            if(atual <= m) ans = max(ans, atual);
        }
    }

    cout << ans << endl;

}

signed main(){

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
