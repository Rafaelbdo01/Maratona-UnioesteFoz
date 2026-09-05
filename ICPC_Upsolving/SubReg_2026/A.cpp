//Link para a questão:  https://codeforces.com/gym/106679/problem/A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(),x.end()

void solve(){

    int n; cin >> n;

    int psumx = 0, psumy = 0;

    vector<int>buy,sell;

    buy.pb(0);
    sell.pb(0);

    for(int i=0;i<n;i++){

        int x, y; cin >> x >> y;

        psumx+=x; psumy+=y;

        buy.pb(psumx);
        sell.pb(psumy);
    }

    int q; cin >> q;

    for(int i=0;i<q;i++){

        int x; cin >> x;

        if(buy[x] > sell[x]){

            cout << "COMPRA\n";
            continue;
        }

        else if(sell[x] > buy[x]){

            cout << "VENDA\n";
            continue;
        }

        else if(sell[x] == buy[x]){

            cout << "NEUTRO\n";
        }
    }

}

signed main(){

    cin.tie(0) -> sync_with_stdio(0);

    int t=1;
    //cin >> t;

    while(t--) solve();

    return 0;
}