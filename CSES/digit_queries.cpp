#include <bits/stdc++.h>

using namespace std;

//ordered_set start
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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





int getBit(ll n, int bit){
    bit++;
    // cout<<"\n"<<n<<" "<<bit<<" ";
    int c = 0;
    while(bit--){
        c = n%10;
        n/=10;
    }
    return c;
}

void solve() {
    ll q;
    cin>>q;
    
    ll cnt = 1, cur = 0;

    ll fac = 1, next = 0, sum = 0;; 
    while(1){
        fac *= 10;
        next = fac - sum - 1; // 9, 90
        // cout<<"next: "<< next<<" ";
        sum += next;
        if( q> (cnt * next) ){
            q -= (cnt * next); //q=10
            cur += next;     // cur = 9
        }
        else{
            cur += (q/cnt);    //cur = 14
            // cout<<sum<<" ";
    	    cout<<getBit(cur + ((q%cnt)!=0), (cnt - (q%cnt))%cnt);
    	    return;
    	}
    // 	cout<<"cur: "<<cur<<" ";
    // 	cout<<"q: " <<q<<"\n";
    	cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
        cout<<"\n";
    }
}

