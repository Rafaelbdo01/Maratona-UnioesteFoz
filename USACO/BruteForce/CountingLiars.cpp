//Link da questao: http://usaco.org/index.php?page=viewproblem2&cpid=1228

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

void solve(){

    int n; cin >> n;

    vector<pair<int,char>> cows;
    vector<int>p;

    for(int i=0;i<n;i++){

        int x;
        char c;

        cin >> c >> x;

        cows.pb({x,c});
    }

    sort(all(cows));

    for(int i=0;i<n-1;i++){

        auto [x2,c2] = cows[i+1];

        p.pb(x2 - 1);
        p.pb(x2+1);
        p.pb(x2);
    }

    int ans = INF;
    sort(all(p));

    for(auto a : p){

        int l = 0;

        for(int j=0;j<n;j++){

            auto [x, c] = cows[j];

            if(c == 'L' and a > x) l++;
            else if(c == 'G' and a < x) l++;
        }

        ans = min(ans, l);
    }

    cout << ans << endl;

}

signed main(){

    //freopen("cowsignal.in", "r", stdin);
    //freopen("cowsignal.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
