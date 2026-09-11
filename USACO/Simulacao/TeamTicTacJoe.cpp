//Link da questao: http://www.usaco.org/index.php?page=viewproblem2&cpid=831

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

void checa(char a, char b, char c, set<char> &solo, set<set<char>> &duplas){

    set<char> temp = {a,b,c};

    if(temp.size() == 1){

        solo.insert(*temp.begin());
        return;
    }

    else if(temp.size() == 2){

        duplas.insert(temp);
        return;
    }
}

void solve(){

    vector<vector<char>> mat(3, vector<char>(3, '#'));

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

            cin >> mat[i][j];
        }
    }

    set<char> solo;
    set<set<char>> duplas;

    //Linha
    for(int i=0;i<3;i++){
        
        checa(mat[i][0], mat[i][1], mat[i][2], solo, duplas);
    }

    //Coluna
    for(int i=0;i<3;i++){
        
        checa(mat[0][i], mat[1][i], mat[2][i], solo, duplas);
    }

    //Diagonal P
    checa(mat[0][0], mat[1][1], mat[2][2], solo, duplas);

    //Diagonal S
    checa(mat[0][2], mat[1][1], mat[2][0], solo, duplas);

    cout << solo.size() << endl << duplas.size() << endl;
}

signed main(){

    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    
    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}