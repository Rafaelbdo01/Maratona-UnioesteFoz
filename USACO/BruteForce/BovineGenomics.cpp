//Link para a questao: https://usaco.org/index.php?page=viewproblem2&cpid=736

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

void solve(){

    int n, m; cin >> n >> m;

    vector<string>spot(n), plain(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            char c; cin >> c;

            spot[i] += c;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            char c; cin >> c;

            plain[i] += c;
        }
    }

    int ans = 0;

    for(int i=0;i<m;i++){

        bool diff = true;
        string s1, s2;

        for(int j=0;j<n;j++){

            s1 += spot[j][i];
            s2 += plain[j][i];
        }

        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){

                if(s1[j] == s2[k]) diff = false;
            }
        }

        if(diff) ans++;
    }

    cout << ans << endl;

}

signed main(){

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
