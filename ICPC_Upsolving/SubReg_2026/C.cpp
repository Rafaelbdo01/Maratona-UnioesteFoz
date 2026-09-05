//Link para a questão: https://codeforces.com/gym/106679/problem/C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(),x.end()

void solve(){

    int t,c,k; cin >> t >> c >> k;

    int exch = k * t;

    cout << min(exch, c) << endl;

}

signed main(){

    cin.tie(0) -> sync_with_stdio(0);

    int t=1;
    //cin >> t;

    while(t--) solve();

    return 0;
}