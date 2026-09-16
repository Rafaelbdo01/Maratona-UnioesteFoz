//Link da questão: https://usaco.org/index.php?page=viewproblem2&cpid=1060

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

    vector<int>flower(n+1);

    for(int i=1;i<=n;i++) cin >> flower[i];

    set<pair<int,int>> ans;

    for(int i=1;i<=n;i++){

        float avg = 0;
        float sum = 0;

        for(int j=i;j<=n;j++){

            sum += flower[j];

            float div = abs(i - j) + 1;
            avg = sum / div;

            for(int k=i;k<=j;k++){

                if(flower[k] == avg){

                    ans.insert({min(i,j), max(i,j)});

                    break;
                }
            }
        }
    }

    cout << ans.size() << endl;

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
