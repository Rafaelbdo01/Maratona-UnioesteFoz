#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define joaobobao cin.tie(0)->sync_with_stdio(0)
#define all(x) x.begin(), x.end()

void solve(){

    int n; cin >> n;
    map<int, vector<pair<string,int>>> dias;
    map<string,int>leite;
    vector<tuple<int,string,char,int>> tralala;

    for(int i=0;i<n;i++){

        int x, y;
        char c;
        string temps;

        cin >> x >> temps >> c >> y;
        tralala.pb({x,temps,c,y});
    }

    sort(all(tralala));

    for(auto [x,s,c,y] : tralala){

        auto it = dias.find(x);

        if(it == dias.end()){
            if(c == '+') dias.insert({x, {{s, y}}});
            else dias.insert({x, {{s, -y}}});
        }

        else{
            if(c == '+') dias.at(x).pb({s, y});
            else dias.at(x).pb({s, -y});
        }
    }

    string x;
    string last;
    int ans = 0;

    for(auto i=dias.begin();i!=dias.end();i++){
        
        if(x != last) ans++;

        last = x;

        for(auto [s, y] : i->second){

            auto it = leite.find(s);

            if(it == leite.end()) leite.insert({s, 7 + y});
            else leite.at(s) += y;
        }

        string s;

        for(auto tit = leite.begin();tit != leite.end();tit++){

            
        }
    }

    cout << ans << endl;
}

signed main(){

    joaobobao;

    //freopen("measurement.in", "r", stdin);
    //freopen("measurement.out", "w", stdout);

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
