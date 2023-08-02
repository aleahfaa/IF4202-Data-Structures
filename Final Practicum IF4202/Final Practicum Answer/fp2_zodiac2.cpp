/*077's notes:
input:
jml bintang yg bakal dicari kemungkinannya
byk bintang
output:
byk kemungkinan rasi bintang
"Zodiak found: {hasil} signs"
fp2_zodiac (cpp mode)*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000009;

ll powfunc(ll x, ll y){
    ll res = 1;
    while(y > 0){
        if(y & 1){
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

ll gpow(ll n){
    return (n * (n - 1)) / 2;
}

int main(){
    ll m, n;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> n;
        ll pwr = gpow(n);
        ll res = powfunc(2, pwr) % mod;
        cout << "Zodiak found: " << res << " signs" << endl;
    }
}
