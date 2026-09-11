//Link da questao: https://usaco.org/index.php?page=viewproblem2&cpid=664

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

void solve(){

    int n; cin >> n;

    vector<pair<string,string>> vec;
    vector<int>alf(26, 0);

    for(int i=0;i<n;i++){

        string s1, s2;
        cin >> s1 >> s2;
        
        vec.pb({s1,s2});
    }

    for(auto a : vec){

        vector<int>tempalf1(26,0);
        vector<int>tempalf2(26,0);

        auto s1 = a.first;
        auto s2 = a.second;

        for(char c : s1) tempalf1[c - 'a']++;
        for(char c : s2) tempalf2[c - 'a']++;

        for(int i=0;i<26;i++){

            alf[i] += max(tempalf1[i], tempalf2[i]);
        }
    }
    
    for(auto a : alf){

        cout << a << endl;
    }

}

signed main(){

    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}