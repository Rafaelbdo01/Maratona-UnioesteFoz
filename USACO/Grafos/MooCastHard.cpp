//Link da questao: https://usaco.org/index.php?page=viewproblem2&cpid=669

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

int calc(int x1, int x2, int y1, int y2){

    int x = abs(x2-x1) * abs(x2-x1);
    int y = abs(y2-y1) * abs(y2-y1);

    return x + y;
}

bool bfs(int x, vector<pair<int,int>> &g, vector<int> visited, int n){

    queue<int> q;
    int count = 1;
    q.push(0); visited[0] = 1;

    while(!q.empty()){

        auto u = q.front(); q.pop();

        for(int i=0;i<n;i++){

            if(!visited[i] and calc(g[u].f, g[i].f, g[u].s, g[i].s) <= x){

                count++;
                q.push({i});
                visited[i] = 1;
            }
        }
    }

    return count == n;
}

void solve() {

    int n; cin >> n;
    vector<pair<int, int>> g(n);

    for(int i=0;i<n;i++){

        int x, y; cin >> x >> y;
        g[i] = {x, y};
    }

    int lo = 0, hi = 2 * (25000 * 25000), ans = hi;

    while(lo <= hi){

        int mid = lo + (hi - lo) / 2;
        vector<int> visited(n, 0);

        if(bfs(mid, g, visited, n)){

            ans = mid;
            hi = mid - 1;
        }

        else lo = mid + 1;
    }

    cout << ans << endl;
}


signed main() {

    fastio;

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int t = 1;  
    //cin >> t;

    while (t--) solve();

    return 0;
}
