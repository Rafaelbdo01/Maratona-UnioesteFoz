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
    vector<string>pal, pal2, pal3;

    for(int i=0;i<n;i++){

        string s; cin >> s;

        pal.pb(s);
    }

    for(int i=0;i<n;i++){

        string temp = pal[i];

        for(int j=0;j<n;j++){

            if(i == j) continue;

            string concatenadas = temp + pal[j];

            pal2.pb(concatenadas);
        }
    }

    for(auto a : pal2){

        reverse(all(a));
        pal3.pb(a);
    }

    int ans = 0;

    for(int i=0;i<min(pal2.size(), pal3.size());i++){

        if(pal2[i] == pal3[i]) ans++;
    }

    cout << ans << endl;

}

signed main(){

    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
