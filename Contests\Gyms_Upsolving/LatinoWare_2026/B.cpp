#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

void solve(){

    int n, k; cin >> n >> k;

    if (n%(k+1) == 0){
        
        cout << "Thiago\n";
    }
    
    else{

        cout << "Trojack\n";
    }

}

signed main(){

    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
