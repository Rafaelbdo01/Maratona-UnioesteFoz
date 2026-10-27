#Link da questao: https://usaco.org/index.php?page=viewproblem2&cpid=761

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define joaobobao cin.tie(0)->sync_with_stdio(0)
#define all(x) x.begin(), x.end()

typedef struct{

    int dia;
    string nome;
    int acrescimo;

} cow;

void solve(){

    int n; cin >> n;
    vector<cow>mumu;
    map<string,int> leite;
    vector<int>dias;

    for(int i=0;i<n;i++){

        int x, y;
        char c;
        string s;

        cin >> x >> s >> c >> y;

        if(c == '+') mumu.pb({x,s,y});
        else mumu.pb({x,s,-y});

        auto it = leite.find(s);

        if(it == leite.end()) leite.insert({s, 7});
        dias.pb(x);
    }

    sort(mumu.begin(), mumu.end(), [](const auto &a, const auto &b){

        return a.dia < b.dia;
    });

    unique(all(dias));
    sort(all(dias));

    int ans = 0;
    vector<vector<string>>winners(101);
    int aux = 0;

    for(auto i : dias){
        for(int j=aux;j<n;j++){

            if(mumu[j].dia == i) leite.at(mumu[j].nome) += mumu[j].acrescimo;

            if(mumu[j].dia > i or i == dias.back()){

                int maior = 0;

                for(auto it = leite.begin();it!=leite.end();it++){

                    maior = max(maior, it->second);
                }

                for(auto it = leite.begin();it!=leite.end();it++){

                    if(it->second == maior) winners[i].pb({it->first});
                }

                aux = j;
                break;
            }
        }
    }

    for(int i=0;i<dias.size();i++){

        vector<string>temp1, temp2;

        for(int j=0;j<winners[dias[i]].size();j++){

            temp1.pb(winners[dias[i]][j]);
        }

        if(i != 0){
            for(int j=0;j<winners[dias[i-1]].size();j++){

                temp2.pb(winners[dias[i-1]][j]);
            }
        }

        if(temp1 != temp2) ans++;

    }

    cout << ans << endl;
}

signed main(){

    joaobobao;

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
