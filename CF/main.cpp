#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const char nl = '\n';

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t; cin >> t;
  while(t--){
    ll n; cin >> n;
    if( n <= 6){
      cout << 15 << nl;
      continue;
    }
    ll tmp = n;
    ll x= n/10 * 25;
    n %= 10;
    if(n == 0){
      cout << x << nl;
    }
    else if(n > 8){
      cout <<  x + 25 << nl;
    }
    else if( n == 4 || n == 3){
      cout << x - 25 + 15 + 20 << nl;
    }
    else if(n == 2 || n == 1){
      cout << x - 25 + 15 + 15 << nl;
    }
    else if(n == 8 || n == 7){
      cout << x + 20 << nl;
    }
    else{
      cout << x + 15 << nl;
    }


  }

}
