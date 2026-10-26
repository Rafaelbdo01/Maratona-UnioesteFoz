#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define joaobobao cin.tie(0)->sync_with_stdio(0)

void solve(){

    string s, t, final;
    cin >> s >> t;

    for(int i=0;i<s.size();i++){
        
        final += s[i];
        string temp;
        int x = ((int)final.size()) - ((int)t.size());
        
        for(int j=final.size()-1;j>=x;j--){
            
            if(j >= 0){

                temp += final[j];
            }
        }

        reverse(temp.begin(), temp.end());

        if(temp == t){

            for(int j=0;j<t.size() and !final.empty();j++) final.pop_back();
        }
    }

    cout << final << endl;
}

signed main(){

    joaobobao;

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    int t = 1;
    //cin >> t;

    while(t--) solve();

    return 0;
}
