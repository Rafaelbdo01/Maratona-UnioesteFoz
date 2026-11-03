#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)

int w;
vector<int>selected;
vector<pair<int,int>> u;
unordered_map<int,int> m;
bool visited[5][1 << 26]{};
vector<string>pal;

void getmask(string s, int i){

    int tempm=0;

    for(char c : s){

        tempm |= (1 << (c - 'a'));
    }

    if(m.find(tempm) == m.end()){

        m[tempm] = i;
        u.pb({tempm, i});
    }
}

int dfs(int idx, int d, int atual){

    int bits = __builtin_popcount(atual);

    if(d == 5) return bits >= 23;

    int maximo = bits + (5 - d) * 5;
    if(maximo < 23){

        return 0;
    }

    if(visited[d][atual]) return 0;

    visited[d][atual] = 1;

    int total = u.size();
    for(int i=idx;i<total;++i){

        selected.pb(u[i].second);

        if(dfs(i, d+1, atual | u[i].first)) return 1;
        
        selected.pop_back();
    }

    return 0;
}

void solve(){

    cin >> w;
    pal.resize(w);

    for(int i=0;i<w;++i){

        string s; cin >> s;

        pal[i] = s;
        getmask(s, i);
    }

    if(!dfs(0,0,0)){

        cout << "-1\n";
        return;
    }

    for(auto a : selected){

        cout << pal[a] << endl;
    }
}

int main(){

    joaobobao;

    int t=1; // cin >> t;

    while(t--) solve();

    return 0;
}
