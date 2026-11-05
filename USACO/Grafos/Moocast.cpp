//Link da questão: https://usaco.org/index.php?page=viewproblem2&cpid=668&lang=en

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

struct cow{
    
    int x, y, p;
};

vector<int>visited;
queue<tuple<int,int,int>> q;
vector<cow>g;
int n;

float calcd(int gx, int gy, int x, int y){
    
    float rx = abs(gx - x);
    float ry = abs(gy - y);
    
    return sqrt((rx * rx) + (ry * ry));
}

int bfs(int s){
    
    visited.clear();
    visited.resize(n+1, 0);
    
    int count = 1;
    
    q.push({g[s].x, g[s].y, g[s].p});
    visited[s] = 1;
    
    while(!q.empty()){
        
        auto [x, y, p] = q.front(); q.pop();
        
        for(int i=1;i<=n;i++){
            
            if(!visited[i]){
                
                float dist = calcd(g[i].x, g[i].y, x, y);
                
                if(dist <= p){
                    
                    q.push({g[i].x, g[i].y, g[i].p});
                    visited[i] = 1;
                    count++;
                }
            }
        }
    }
    
    return count;
}

int main(){
    
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    
    cin.tie(0) -> sync_with_stdio(0);
    
    cin >> n;
    g.resize(n+1);
    visited.resize(n+1, 0);
    
    for(int i=1; i<=n; i++) cin >> g[i].x >> g[i].y >> g[i].p;
    
    int ans = 0;
    
    for(int i=1;i<=n;i++){
        
        ans = max(ans, bfs(i));
    }
    
    cout << ans << endl;
    
    return 0;
}
