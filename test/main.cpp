#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define asd cout << "ok" << endl;
#define trav(i, n) for(int i= 0; i <n; i++)
const char nl = '\n';
const int maxN = 2e5 + 4;
int mod = 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n ; cin >> n;
  vi v(n);
  for(int i = 0; i < n; i++) cin>> v[i];
  vector<string> ans;
  string tmp = "";
  int x = v[0];
  while(x >= 9){
    tmp = "9" + tmp;
     x -= 9;
  }
  if(x > 0) tmp = to_string(x) + tmp;
  ans.pb(tmp);

  for(int i = 1; i < n; i++){
    int x = v[i];
    if(v[i] <= v[i-1]){
      char ch = ans[i-1][0];
      int k = ch - '0';
      if(x > k && ch != '9'){
          x -= (k+1);
          string tmp ="";
          while(x >= 9){
            tmp = "9" + tmp;
            x -= 9;
          }
          tmp = to_string(x) + tmp;
          tmp = to_string(k+1) + tmp;
          ans.pb(tmp);
      }
      else {
        x--;
        string tmp = "";
        while(x >= 9){
          tmp = "9" + tmp;
          x -=9;
        }
        tmp = to_string(x) + tmp;
        for(int i = tmp.size(); i < ans[ans.size()-1].size(); i++){
          tmp = "0" + tmp;
        }

        tmp = "1" + tmp;
        ans.pb(tmp);


      }

    }
    else{
      string ma = ans[i-1];
      int diff = v[i] - v[i-1];
      for(int i = ma.size()-1; i >=0; i--){
        int tmp = ma[i] - '0' + diff;
        if(tmp > 9){
          diff -= '9' - ma[i];
          ma[i] = '9';
        }
        else{
          ma[i] = ma[i] + diff;
          diff = 0;
        }
        if(diff <= 0)
          break;
      }
      while(diff >= 9){
        ma = "9" + ma;
        diff -=x;
      }
      if(diff) ma = to_string(diff) + ma;
      ans.pb(ma);
    }

  }
  for(auto x: ans) cout << x << nl;


}
