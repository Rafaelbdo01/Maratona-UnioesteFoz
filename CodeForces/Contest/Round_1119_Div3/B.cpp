//Link para a questão: https://codeforces.com/contest/2259/problem/B

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

    int impares = 0, divpar = 0, divimpar = 0;

    for(int i=0;i<n;i++){

        int x; cin >> x;

        if(x % 2 == 0){

            if((x / 2) % 2 == 0) divpar++;

            else if((x / 2) % 2 != 0) divimpar++;
        }

        else if(x % 2 != 0){
            
            impares++;
        }
    }

    auto maior_par = max(divpar, divimpar);

    cout << max(impares, maior_par) << endl;

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