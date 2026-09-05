//Link para a questão: https://codeforces.com/gym/106679/problem/K
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(),x.end()

void solve(){

    int n; cin >> n;

    vector<int>estoque(n),exigencia(n);
    vector<pair<int,int>> final;

    for(int i=0;i<n;i++) cin >> estoque[i];
    for(int i=0;i<n;i++) cin >> exigencia[i];

    for(int i=0;i<n;i++) final.pb({estoque[i], exigencia[i]});

    sort(final.begin(),final.end(), [](const auto &a, const auto &b){

        if(a.first != b.first) return a.first > b.first;

        else if(a.first == b.first) return (a.first - a.second) < (b.first - b.second);
    });

    int menor = 1e8, idx = 0;

    for(int i=0;i<n;i++){

        auto a = final[i];

        if(a.second > a.first){

            cout << -1 << endl;
            return;
        }

        if(a.first - a.second < menor){

            menor = a.first - a.second;
            idx = i;
        }
    }

    int ans = 0;

    for(int i=0;i<n;i++){

        if(i == idx){

            ans += final[i].second;
        }

        else ans += final[i].first;
    }

    cout << ans << endl;

    //for(auto a : final) cout << a.first << " : " << a.second << endl;
}

signed main(){

    cin.tie(0) -> sync_with_stdio(0);

    int t=1;
    //cin >> t;

    while(t--) solve();

    return 0;
}