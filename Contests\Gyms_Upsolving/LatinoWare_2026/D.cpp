#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

void solve(){

    int n, k; cin >> n >> k;

    vector<pair<int,int>> video;

    for(int i=0;i<n;i++){

        int x, y; cin >> x >> y;

        video.pb({x, y});
    }

    int seg = 0, watched = 0;

    for(int i=0;i<n;i++){

        auto [a, b] = video[i];

        if(b < k) continue;

        watched++;
        seg += a;
        k++;
    }

    if(watched > (n / 2)){

        cout << "-1\n";
    }

    else{

        cout << seg << endl;
    }
}

signed main(){
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
