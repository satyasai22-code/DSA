#include <bits/stdc++.h>

using namespace std;

//ordered_set start
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//ordered_set end

void dbg_out() { cerr << endl; }

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    ll n, m, k;
    cin>>n>>m>>k;
    vector<ll> a(n, 0);
    for(auto &i: a) cin>>i;
    vector<ll> b(m, 0);
    for(auto &i: b) cin>>i;
    sort(all(a));
    sort(all(b));
    int i = 0, j = 0;
    ll ans = 0;
    while(i<n and j<m){
        ll left = a[i] - k, right = a[i] + k ;
        if(b[j] >= left and b[j] <= right){
            ans++;
            i++;j++;
        }
        else if(b[j] < left) j++; 
        else i++;
    }
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        cout<<"\n";
    }
}

