//Link da questão: https://usaco.org/index.php?page=viewproblem2&cpid=617

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define INF 1e9
#define joaobobao cin.tie(0) -> sync_with_stdio(0)

void solve(){

    int n, m; cin >> n >> m;
    vector<pair<int,int>> cows(n);
    vector<int> north, east;

    for(int i=0;i<n;i++){

        int x, y; cin >> x >> y;

        cows[i] = {x, y};
        north.pb(x + 1); east.pb(y + 1);
    }

    int ans = INF;

    for(auto a : north){
        for(auto b : east){

            int q1 = 0, q2 = 0, q3 = 0, q4 = 0;

            for(auto [x,y] : cows){

                if(x > a and y > b) q1++;
                if(x > a and y < b) q2++;
                if(x < a and y < b) q3++;
                if(x < a and y > b) q4++;
            }

            ans = min(ans, max({q1,q2,q3,q4}));
        }
    }

    cout << ans << endl;
}

signed main(){

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    joaobobao;

    int t=1; // cin >> t;

    while(t--) solve();

    return 0;
}
