//Link para a questão: 

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

    int n; cin >> n;

    queue<pair<int,int>> q;
    q.push({1, 1})

    int i = 1, ans = 1;
    
    while(i <= n){

        auto it = q.front();

        if(it == a.end()){

            ans++;
            b.insert({i, ans});
            a.insert({ans, i});
        }

        else if(it != a.end()){

            ans = (a.at(i) * 3);

            b.insert({i, ans});
            a.insert({ans, i});
        }

        i++;
    }

    cout << ans << endl;

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