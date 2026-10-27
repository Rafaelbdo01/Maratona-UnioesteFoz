//Link para a questao: https://usaco.org/index.php?page=viewproblem2&cpid=1061

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

typedef struct{

    int x,y;
    int idx;

} vaquinha;

void solve(){

    int n; cin >> n;
    vector<vaquinha> north, east;
    
    for(int i=0;i<n;i++){

        int x,y;
        char c;

        cin >> c >> x >> y;

        if(c == 'N') north.pb({x, y, i});
        else east.pb({x,y,i});
    }

    sort(north.begin(), north.end(), [](const auto &a, const auto &b){
        return a.x < b.x;
    });

    sort(east.begin(), east.end(), [](const auto &a, const auto &b){
        return a.y < b.y;
    });

    vector<int>stop(n, -1);

    for(auto n : north){
        for(auto e : east){

            if(n.x > e.x and e.y > n.y){

                int distn = e.y - n.y;
                int diste = n.x - e.x;

                if(distn < diste and stop[e.idx] == -1) stop[e.idx] = n.x;

                else if(diste < distn and stop[e.idx] == -1) {stop[n.idx] = e.y; break;}
            }
        }
    }

    vector<int>dist(n, -1);

    for(auto n : north){

        if(stop[n.idx] != -1){

            dist[n.idx] = stop[n.idx] - n.y;
        }
    }

    for(auto e : east){

        if(stop[e.idx] != -1){

            dist[e.idx] = stop[e.idx] - e.x;
        }
    }

    for(auto d : dist){

        if(d == -1) cout << "Infinity\n";
        else cout << d << endl;
    }
}

signed main(){

    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;   
}
