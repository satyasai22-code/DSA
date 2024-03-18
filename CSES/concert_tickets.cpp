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

ll lowerbound(vector<ll>& arr, ll num){
    int n = arr.size();
    // cout<<"size: "<<n;
    int ans = -1, left = 0, right = n - 1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] == num){
            ans = mid;
            break;
        }
        else if(arr[mid] < num){
          ans = mid;
          left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    if(ans == -1) return -1;
    ll a = arr[ans];
    while(ans < n){
        arr[ans] = arr[ans + 1];
        ans++;
    }
    // for(auto i: arr) cout<<i<<" ";
    // cout<<endl;
    arr.pop_back();
    return a;
}

void solve() {
    ll n, m;
    cin>>n>>m;
    // vector<ll> a(n, 0);
    multiset<ll> st;
    for(int i = 0;i<n;i++){
       ll x;  cin>>x;
       st.insert(x);
    }
    // vector<ll> b(m, 0);
    for(int i = 0;i<m;i++) {
       ll x;  cin>>x;
       auto it = st.upper_bound(x);
       if(it == st.begin()) cout<<-1;
       else{
           --it;
            cout<< *(it);
            st.erase(it);
       }
       cout<<"\n";
    }

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

