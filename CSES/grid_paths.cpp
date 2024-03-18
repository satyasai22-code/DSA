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
int ans = 0;
vector<vector<int>> adj(7, vector<int>(7, 0));
vector<vector<int>> dp(7, vector<int>(7, -1));
const int n = 7;

inline bool valid(int i, int j) {
    return (i < 7 && j < 7 && i >= 0 && j >= 0 && !adj[i][j]);
}

inline bool isValid(int i) {
    return (i < 7 && i >= 0);
}
ll helper(int i, int j, int index, string& s){
    if(!valid(i, j)) return 0;
    //Optimization 2
    if((i == 6) and (j == 0)){
        ans += (index>=48);
        return (index>=48);
    }
    if(index >= 48) 
        return 0;
        
    // Optimization 3, 4: If we hit wall or path that divides the box into left and right(ultimately all squares are not visited by this..so should be stopped here)
    if(((i + 1 == 7 || i == 0) || (adj[i - 1][j] and adj[i + 1][j])) && isValid(j - 1) and isValid(j + 1) && !adj[i][j + 1] && !adj[i][j-1]) return 0;
    // if((i == 0 || (adj[i - 1][j] and adj[i + 1][j])))
    if(((j + 1 == 7 || j == 0) || (adj[i][j - 1] and adj[i][j + 1])) &&  isValid(i - 1) and isValid(i + 1)&& !adj[i - 1][j] && !adj[i + 1][j]) return 0;
    
//     if (((i + 1 == n || i == 0 || j == 0 || j + 1 == n || (adj[i - 1][j] && adj[i + 1][j])) && isValid(j - 1) && isValid(j + 1) && !adj[i][j - 1] && !adj[i][j + 1])) {
// 		return 0;
// 	}
// 	if (((i + 1 == n || i == 0 || j == 0 || j + 1 == n  || (adj[i][j - 1] && adj[i][j + 1])) && isValid(i - 1) && isValid(i + 1) && !adj[i - 1][j] && !adj[i + 1][j])) {
// 		return 0;
// 	}
    ll a = 0;
    adj[i][j] = 1;
    if(s[index] == 'R' or s[index] == '?'){
            // cout<<index<<":"<<s[index]<<"\n";
        a += helper(i, j + 1, index + 1, s);
    }
    if(s[index] == 'L' or s[index] == '?'){
            // cout<<index<<":"<<s[index]<<"\n";
        a += helper(i, j - 1, index + 1, s);
    }
    if(s[index] == 'U' or s[index] == '?'){
            // cout<<index<<":"<<s[index]<<"\n";
        a += helper(i - 1, j , index + 1, s);
    }
    if(s[index] == 'D' or s[index] == '?'){
            // cout<<index<<":"<<s[index]<<"\n";
        a += helper(i + 1, j , index + 1, s);
    }
    adj[i][j] = 0;
    return a;
}

void solve() {
    string str;
    cin>>str;
    ll as = helper(0, 0, 0, str);
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

