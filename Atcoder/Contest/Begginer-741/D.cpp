//Link para a questão: https://atcoder.jp/contests/abc471/tasks/abc471_d

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define joaobobao ios_base::sync_with_stdio(false); cin.tie(NULL)


void solve() {

    int q, v, count = 0; cin >> q >> v;

    vector<pair<int, int>> charges;

    for(int i=0;i<q;i++){

        int type, time, bat; cin >> type;

        if(type == 1){

            cin >> time >> bat;

            charges.pb({time, bat});
        }

        else if(type == 2){

            if(count > charges.size()){

                cout << "-1\n";
                continue;
            }

            count++;

            sort(all(charges));

            cin >> time;

            cout << charges.back().s + abs(time - charges[q-1].f) << endl;
        }
    }

}


signed main() {

    joaobobao;
    //freopen('problem_name', 'r', stdin);
    //freopen('problem_name', 'w', stdout);

    int t = 1;
    //cin >> t;

    while (t--) solve();

    return 0;
}