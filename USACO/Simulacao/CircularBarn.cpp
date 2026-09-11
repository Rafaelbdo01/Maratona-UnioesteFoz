// Link da questao: https://usaco.org/index.php?page=viewproblem2&cpid=616

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

    vector<int>barn(n);

    for(int i=0;i<n;i++) cin >> barn[i];

    int ans = 1e8;

    for(int i=0;i<n;i++){

        int path = 0;
        int visited[n]{};
        int diff = 0;

        //cout << "START: " << i << endl;
        for(int j=i;j<n;j++){

            diff = j - i;
            
            path += (barn[j] * diff);
            visited[j] = 1;
            //cout << "PATH += " << barn[j] << " * " << diff << endl;
        }

        for(int k=0;k<i;k++){

            if(!visited[k]){

                path += (barn[k]) * ++diff;
                //cout << "PATH += " << barn[k] << " * " << diff << endl;
            }
        }
        
        //cout << "PATH = " << path << endl;
        ans = min(ans, path);
    }

    cout << ans << endl;
}

signed main(){

    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
} 