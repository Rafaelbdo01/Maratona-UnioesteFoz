//Link para a questão: https://usaco.org/index.php?page=viewproblem2&cpid=639

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

int n, k;

void solve(){

    cin >> n >> k;

    vector<int>dima(n);

    for(int i=0;i<n;i++) cin >> dima[i];

    int ans = 1;

    sort(dima.begin(), dima.end(), [](const auto &a, const auto &b){

        return a > b;
    });

    //for(auto a : dima) cout << a << " ";

    for(int i=0;i<n;i++){

        int menor = dima[i];
        int maior = dima[i];
        int atual = 1;

        //cout << "I = " << dima[i] << endl << "Diamonds = ";

        for(int j=0;j<n;j++){

            if(i == j) continue;

            if(abs(dima[j] - maior) <= k){
                if(abs(dima[j] - menor) <= k){

                    atual++;
                    maior = max(maior, dima[j]);
                    menor = min(menor, dima[j]);

                    //cout << dima[j] << " ";
                }
            }
        }

        //cout << endl;
        //cout << "Menor = " << menor << "|| Maior = " << maior << endl;
        //cout << "Atual = " << atual << endl;

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
