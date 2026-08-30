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
    q.push({1, 2});

    if(n == 1){
        cout << 2 << endl;
        return;
    }

    int i = 2, ans = 1;
    
    while(i <= n){

        auto [x, y] = q.front();
        auto [w, z] = q.back();

        if(i == y){

            q.pop();

            ans = x * 3;
            q.push({i, ans});
        }

       

        if(i != y){

            ans = z+1;
            q.push({i, ans});
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
