//Link da questao: https://usaco.org/index.php?page=viewproblem2&cpid=917

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
    vector<tuple<string,int,int>> traffic;

    for(int i=0;i<n;i++){

        string s; int x, y;
        cin >> s >> x >> y;
        
        traffic.pb({s, x, y});
    }

    pair<int,int>range = {0,INF};

    //Antes de 1
    for(int i=n-1;i>=0;i--){

        auto [x,y,z] = traffic[i];

        if(x == "on"){

            range.first = max(0LL, range.first - z);
            range.second -= y;
            continue;
        }

        else if(x == "off"){

            range.first += y;
            range.second += z;
            continue;
        }

        else if(x == "none"){

            range.first = max(range.first, y);
            range.second = min(range.second, z);
            continue;
        }
    }

    cout << range.first << " " << range.second << endl;

    range = {0, INF};

    //Apos N

    for(int i=0;i<n;i++){

        auto [x,y,z] = traffic[i];

        if(x == "off"){

            range.first = max(0LL, range.first - z);
            range.second -= y;
            continue;
        }

        else if(x == "on"){

            range.first += y;
            range.second += z;
            continue;
        }

        else if(x == "none"){

            range.first = max(range.first, y);
            range.second = min(range.second, z);
            continue;
        }
    }

    cout << range.first << " " << range.second << endl;

}

signed main(){

    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
