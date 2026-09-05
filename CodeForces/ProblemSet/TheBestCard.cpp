//Link para a questão: https://codeforces.com/contest/2253/problem/A

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

vector<bool>primo;

void crivo(int n){

    for(int i=2;i*i<=n;++i){

        if(primo[i]){

            for(int j=i*i;j<=n;j+=i){

                primo[j] = false;
            }
        }
    }
}

void solve(){

    int n; cin >> n;

    primo.resize(n+2, true);
    primo[0] = false; primo[1] = false;

    crivo(n+2);
    int maior = 0;

    for(int i=2;i<=n+1;i++){

        if(primo[i]){

            maior = max(maior, i);
        }
    }

    if(maior < n+1){

        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

signed main(){

    //freopen("cowsignal.in", "r", stdin);
    //freopen("cowsignal.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    cin >> t;

    while(t--) solve();

    return 0;
}