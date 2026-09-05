//Link para a questão: https://codeforces.com/contest/2259/problem/C

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define f first
#define s second
#define joaobobao ios_base::sync_with_stdio(false); cin.tie(NULL)


void solve() {

    int n; cin >> n;

    vector <int> num(n);

    for(int i=0;i<n;i++) cin >> num[i];

    if(n == 1 and num[0] == -1) {cout << 1 << endl; return;}

    int ult_um = 0;

    for(int i=n-1;i>=0;i--){

        if(num[i] == 1 or num[i] == -1){ult_um = i;break;}
    }

    tuple<int,int,int> atual = {0, -1, -1}, maior = {0, -1, -1};

    int l = 0;
    while(l<n){

        if(num[l] == 0){l++; continue;}

        else if(num[l] == -1){

            atual = {0, l, 0};

            for(int i=l+1;i<n;i++){

                if(num[i] == 0){(get<0>(atual))++;continue;}

                else if(num[i] == -1 and i != ult_um){(get<0>(atual))++;continue;}

                else if(num[i] == -1 and i == ult_um){

                    if(get<0>(atual) > get<0>(maior)){

                        maior = {get<0>(atual),l,i};
                    }

                    atual = {0,-1,-1};
                    break;
                }

                else if(num[i] == 1 and i == ult_um){

                    if(get<0>(atual) > get<0>(maior)){

                        maior = {get<0>(atual),l,-1};
                    }

                    atual = {0,-1,-1};
                    break;
                }
            }

            l++;
        }

        else if(num[l] == 1){

            for(int i=l+1;i<n;i++){

                if(num[i] == 0){(get<0>(atual))++;continue;}

                else if(num[i] == -1 and i != ult_um){(get<0>(atual))++;continue;}

                else if(num[i] == -1 and i == ult_um){

                    if(get<0>(atual) > get<0>(maior)){

                        maior = {get<0>(atual),-1,i};
                    }

                    atual = {0,0,0};
                    break;
                }

                else if(num[i] == 1 and i == ult_um){

                    if(get<0>(atual) > get<0>(maior)){

                        maior = {get<0>(atual),-1,-1};
                    }

                    atual = {0,0,0};
                    break;
                }
            }


            l++;
        }
    }

    auto [x,y,z] = maior;

    for(int i=0;i<n;i++){

        if(i == y or i == z) num[i] = 1;

        else if(num[i] == -1 and i != y and i != z) num[i] = 0;
    }

    for(auto a : num) cout << a << " ";

    cout << endl;
}


signed main() {

    joaobobao;
    //freopen('problem_name', 'r', stdin);
    //freopen('problem_name', 'w', stdout);

    int t = 1;
    cin >> t;

    while (t--) solve();

    return 0;
}