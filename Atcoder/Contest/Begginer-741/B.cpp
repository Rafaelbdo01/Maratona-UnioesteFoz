//Link para a questão: https://atcoder.jp/contests/abc471/tasks/abc471_b

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

    map<string, int> m;

    for(int i=0;i<n;i++){

        string s; cin >> s;

        for (char &c : s) {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }

        auto it = m.find(s);

        if(it == m.end()) m.insert({s, 1});

        else{

            m.at(s)++;
        }
    }

    auto ans = max_element(all(m), [](const auto &a, const auto &b){
        return a.second < b.second;
    });

    cout << ans->second << endl;

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