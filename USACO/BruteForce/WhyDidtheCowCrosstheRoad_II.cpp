//Link para a questao: https://usaco.org/index.php?page=viewproblem2&cpid=712

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

void solve(){

    string s; cin >> s;
    for(auto &a : s) a = tolower(a);
    vector<pair<int,int>> cows(26);

    for(char c='a';c<='z';c++){
        for(int i=0;i<52;i++){

            if(s[i] == c){
                
                cows[c-'a'].first = i;
            }
        }

        for(int i=52;i>=0;i--){

            if(s[i] == c){

                cows[c-'a'].second = i;
            }
        }
    }

    set<pair<int,int>> ans;

    for(int i=0;i<26;i++){

        auto [x, y] = cows[i];

        for(int j=0;j<26;j++){

            auto [w, z] = cows[j];

            if(j == i) continue;

            if(x < w and y < z and x > z) ans.insert({min(i,j), max(i,j)});
        }
    }

    cout << ans.size() << endl;

}

signed main(){

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
