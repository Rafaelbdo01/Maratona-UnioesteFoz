//Link para a questao: https://usaco.org/index.php?page=viewproblem2&cpid=856
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
    int maxtime = 0;

    vector<tuple<int, int, int>> cows;

    for(int i=0;i<n;i++){

        int x, y, z; cin >> x >> y >> z;

        cows.pb({x, y, z});
        
        maxtime += y;
    }

    vector <bool> buckets{};
    sort(all(cows));

    for(int i=1;i<=maxtime;i++){
        for(int j=0;j<n;j++){

            bool cheios = true;
            int count = 0;
            auto [x, y, z] = cows[j];

            if(x > i) break;

            else if(x == i){

                for(int k=0;k<buckets.size();k++){

                    if(count == z){break;cheios = false;}
                    if(buckets[k] == 1) continue;

                    else if(buckets[k] == 0){
                        
                        buckets[k] = 1;
                        count++;
                    }
                }

                if(cheios){

                    for(int l=0;l<abs(count - z);l++){

                        buckets.pb(1);
                    }
                }
            }

            else if(y == i){

               for(int k=0;k<buckets.size();k++){

                    if(count == z) break;
                    if(buckets[k] == 0) continue;

                    else if(buckets[k] == 1){
                        
                        buckets[k] = 0;
                        count++;
                    }
                } 
            }
        }
    }

    cout << buckets.size() << endl;

}

signed main(){

    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}