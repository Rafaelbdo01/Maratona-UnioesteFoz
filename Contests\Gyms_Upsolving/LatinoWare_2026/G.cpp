#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x .end()
#define rall(x) x.rbegin(), x.rend()
#define joaobobao cin.tie(0) -> sync_with_stdio(0)
#define INF 1e18

int modif(int x, char c){

    switch(c){

        case 'D': return x * 2;
        case 'B': return x + 3;
        case 'R': return 10 - x;

        default: return x;
    }
}

void solve(){

    int n; cin >> n;

    int mandpoints = 0, minezpoints = 0, mandwin = 0, minezwin = 0;

    for(int i=0;i<n;i++){

        int f1, f2;
        char c1, c2;

        cin >> f1 >> c1 >> f2 >> c2;

        f1 = modif(f1, c1);
        f2 = modif(f2, c2);

        if(f1 > f2){

            minezwin++;
            minezpoints += 2;
            mandwin = 0;

            if(minezwin == 3){

                minezpoints += 3;
                minezwin = 0;
            }
        }

        else if(f2 > f1){

            mandpoints+=2;
            mandwin++;
            minezwin = 0;

            if(mandwin == 3){

                mandpoints += 3;
                mandwin = 0;
            }
        }

        else if(f2 == f1){

            mandpoints++;
            minezpoints++;

            mandwin = 0;
            minezwin = 0;
        }
    }

    cout << minezpoints << " " << mandpoints << endl;

    if(minezpoints > mandpoints){

        cout << "Minez\n";
        return;
    }

    else if(minezpoints < mandpoints){

        cout << "Mandelli\n";
        return;
    }

    else{

        cout << "Empate\n";
        return;
    }

}

signed main(){

    joaobobao;

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
