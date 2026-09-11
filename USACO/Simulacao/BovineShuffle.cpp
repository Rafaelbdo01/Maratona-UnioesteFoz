//Link da questao: http://www.usaco.org/index.php?page=viewproblem2&cpid=760

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

    vector <int> trocas(n+1), cows(n+1), s1(n+1), s2(n+1), s3(n+1);

    for(int i=1;i<=n;i++) cin >> trocas[i];
    for(int i=1;i<=n;i++) cin >> cows[i];

    //Shuffle 1
    for(int i=1;i<=n;i++){

        s1[i] = cows[trocas[i]];
    }

    //Shuffle 2
    for(int i=1;i<=n;i++){

        s2[i] = s1[trocas[i]];
    }

    //Shuffle 3
    for(int i=1;i<=n;i++){

        s3[i] = s2[trocas[i]];
    }

    for(int i=1;i<=n;i++) cout << s3[i] << endl;

}

signed main(){

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}