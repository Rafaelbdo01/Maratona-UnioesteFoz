//Link para a questão: https://codeforces.com/contest/2259/problem/A

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

    int n,k; cin >> n >> k;

    vector<vector<int>> farm(n/k+1);

    string s;
    cin >> s;

    int time = 1;
    for(int i=0;i<n;i++){

        farm[time].pb(s[i] - '0');

        if((i+1) % k == 0) time++;
    }

    int ans = 0;

    for(auto a : farm){

        bool zero = false;

        for(auto b : a){
            
            if(b == 0) zero = true;
        }

        if(!zero) ans++;
    } 

    cout << ans - 1 << endl;

/*     for(auto a : farm){
        for(auto b : a){
            cout << b << " ";
        }
        cout << endl;
    } */

}


signed main() {

    joaobobao;
    //freopen('problem_name', 'r', stdin);
    //freopen('problem_name', 'w', stdout);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}