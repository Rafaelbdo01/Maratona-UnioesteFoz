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

    vector<tuple<int, int, string, int>> ans;

    for(int i=0;i<n;i++){

        string s;
        int p,e1,e2,e3,e4,e5,e6;

        cin >> s >> p >> e1 >> e2 >> e3 >> e4 >> e5 >> e6;

        int maiornota = max({e1,e2,e3,e4,e5,e6});
        int menornota = min({e1,e2,e3,e4,e5,e6});

        int pontos = (10 * p) + (e1 + e2 + e3 + e4 + e5 + e6 - (maiornota + menornota));

        ans.pb({pontos, i, s, 1});
    }

    sort(ans.begin(), ans.end(), [](const auto &a, const auto &b){
        
        if(get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
        else return get<1>(a) < get<1>(b);
    });

    for(int i=n-1;i>=0;i--){

        auto [x, y, s,z] = ans[i];
        int maiores = 0;

        for(int j=0;j<n;j++){

            auto [xj, yj, sj, zj] = ans[j];

            if(xj > x) maiores++;

            if(maiores == 3){

                get<3>(ans[i]) = 0;
                break;
            }
        }
    }

    int contawin = 0;

    for(auto [x, y, s, z] : ans){

        if(z != 0){

            contawin++;
            cout << s << " " << x << endl;
        }

        if(contawin == 1000) return;
    }

}

signed main(){

    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
