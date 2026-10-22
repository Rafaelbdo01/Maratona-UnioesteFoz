//Link para a questao: https://usaco.org/index.php?page=viewproblem2&cpid=784

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
    vector<pair<int,int>> cows;
    vector<int>time(1001, 0);

    for(int i=0;i<n;i++){

        int x,y;
        cin >> x >> y;

        cows.pb({x,y});

        for(int j=x+1;j<=y;j++) time[j]++;
    }

    vector<int>temptime = time;

    int ans = 0;

    for(int i=0;i<n;i++){

        auto [x,y] = cows[i];
        temptime = time;

        for(int j=x+1;j<=y;j++) temptime[j]--;

        int contatemp = 0;

        for(int j=0;j<=1000;j++) if(temptime[j] > 0) contatemp++;

        ans = max(contatemp, ans);
    }

    cout << ans << endl;

}

signed main(){

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
