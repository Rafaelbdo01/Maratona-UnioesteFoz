//Link para a questão: https://atcoder.jp/contests/abc471/tasks/abc471_a

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

    float a, b; cin >> a >> b;

    a + b == 9? printf("Nine\n") :
    a - b == 9? printf("Nine\n") :
    a * b == 9? printf("Nine\n") :
    a / b == 9? printf("Nine\n") :
    printf("Nein\n");

}


signed main() {

    //joaobobao;
    //freopen('problem_name', 'r', stdin);
    //freopen('problem_name', 'w', stdout);

    int t = 1;
    //cin >> t;

    while (t--) solve();

    return 0;
}