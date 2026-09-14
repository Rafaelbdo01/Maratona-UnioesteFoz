//Link para a questão: https://usaco.org/index.php?page=viewproblem2&cpid=639

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

void solve(){

    int n,k;
    cin >> n >> k;

    vector<int>dima(n);

    for(int i=0;i<n;i++) cin >> dima[i];

    int ans = 0;

    for(int i=0;i<n;i++){

        int atual = 1;
        vector<int> num;
        num.pb(dima[i]);

        for(int j=0;j<n;j++){

            if(j == i) continue;

            if(abs(dima[i] - dima[j]) <= k){

                bool da = true;

                for(int l=0;l<num.size();l++){

                    if(abs(dima[j] - num[l] > k)) {da = false; break;}
                }

                if(da){

                    atual++;
                    num.pb(dima[j]);
                }
            }
        }

        ans = max(ans, atual);
    }

    cout << ans << endl;

}

signed main(){

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}